// One-time backfill: scans my-solutions/<Difficulty>/<id-slug>/solution*.ext
// files already in the repo, hashes them using the SAME normalization logic
// as the extension, and merges the results into hashes.json at the repo
// root. Safe to re-run — it only ever adds hashes, never removes any.

const fs = require("fs");
const path = require("path");
const crypto = require("crypto");

const ROOT = process.cwd();
const SOLUTIONS_DIR = path.join(ROOT, "my-solutions");
const HASHES_PATH = path.join(ROOT, "hashes.json");

// --- Must stay identical to normalizeCode() in the extension's background
// script, or hashes computed here won't match hashes computed later by the
// extension for the same code. ---
function normalizeCode(code) {
    if (!code) return "";
    return code
        .replace(/\r\n/g, "\n")
        .split("\n")
        .map(line => line.trim().replace(/[ \t]+/g, " "))
        .filter(line => line.length > 0)
        .join("\n");
}

function hashCode(text) {
    return crypto.createHash("sha256").update(text, "utf8").digest("hex");
}

// Folder names look like "0113-path-sum-ii" -> slug is "path-sum-ii"
function extractSlug(folderName) {
    const match = folderName.match(/^\d+-(.+)$/);
    return match ? match[1] : folderName;
}

// Matches solution.cpp, solution_123.py, solution_456.js, etc.
// Skips README.md and anything else that isn't a solution file.
function isSolutionFile(fileName) {
    return /^solution/i.test(fileName);
}

function loadExistingHashes() {
    if (!fs.existsSync(HASHES_PATH)) return {};
    try {
        return JSON.parse(fs.readFileSync(HASHES_PATH, "utf8"));
    } catch (e) {
        console.warn("Could not parse existing hashes.json, starting fresh.");
        return {};
    }
}

function main() {
    if (!fs.existsSync(SOLUTIONS_DIR)) {
        console.log(`No "${SOLUTIONS_DIR}" directory found. Nothing to backfill.`);
        return;
    }

    const hashes = loadExistingHashes();
    let addedCount = 0;
    let scannedFiles = 0;

    const difficulties = fs.readdirSync(SOLUTIONS_DIR, { withFileTypes: true })
        .filter(entry => entry.isDirectory())
        .map(entry => entry.name);

    for (const difficulty of difficulties) {
        const difficultyDir = path.join(SOLUTIONS_DIR, difficulty);

        const problemFolders = fs.readdirSync(difficultyDir, { withFileTypes: true })
            .filter(entry => entry.isDirectory())
            .map(entry => entry.name);

        for (const folderName of problemFolders) {
            const slug = extractSlug(folderName);
            const problemDir = path.join(difficultyDir, folderName);

            const files = fs.readdirSync(problemDir, { withFileTypes: true })
                .filter(entry => entry.isFile())
                .map(entry => entry.name)
                .filter(isSolutionFile);

            if (!hashes[slug]) hashes[slug] = [];

            for (const file of files) {
                scannedFiles++;
                const filePath = path.join(problemDir, file);
                const content = fs.readFileSync(filePath, "utf8");
                const normalized = normalizeCode(content);
                const hash = hashCode(normalized);

                if (!hashes[slug].includes(hash)) {
                    hashes[slug].push(hash);
                    addedCount++;
                    console.log(`+ ${difficulty}/${folderName}/${file} -> recorded new hash for "${slug}"`);
                } else {
                    console.log(`= ${difficulty}/${folderName}/${file} -> hash already known for "${slug}"`);
                }
            }
        }
    }

    fs.writeFileSync(HASHES_PATH, JSON.stringify(hashes, null, 2) + "\n");
    console.log(`\nScanned ${scannedFiles} solution file(s). Added ${addedCount} new hash(es).`);
    console.log(`Wrote ${HASHES_PATH}`);
}

main();
