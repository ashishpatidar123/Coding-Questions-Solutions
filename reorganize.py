import os
import shutil
import json
import requests
import time
import re

repo_dir = os.getcwd()
old_solutions_dir = os.path.join(repo_dir, 'my-solutions')

def get_difficulty(slug):
    query = {
        "query": f'query {{ question(titleSlug: "{slug}") {{ difficulty }} }}'
    }
    headers = {'Content-Type': 'application/json'}
    response = requests.post("https://leetcode.com/graphql", json=query, headers=headers)
    data = response.json()
    return data['data']['question']['difficulty']

def reorganize():
    if not os.path.exists(old_solutions_dir):
        print("my-solutions folder not found! Nothing to reorganize.")
        return

    folders = [f for f in os.listdir(old_solutions_dir) if os.path.isdir(os.path.join(old_solutions_dir, f))]
    
    stats = {"solved": 0, "easy": 0, "medium": 0, "hard": 0, "solvedSlugs": []}

    for folder in folders:
        # Match pattern like "1-two-sum" or just "two-sum"
        match = re.match(r'^\d+-(.+)$', folder)
        slug = match.group(1) if match else folder

        print(f"Fetching difficulty for {slug}...")
        try:
            difficulty = get_difficulty(slug)
            target_dir = os.path.join(repo_dir, difficulty)

            # Create Easy/Medium/Hard folder if it doesn't exist
            if not os.path.exists(target_dir):
                os.makedirs(target_dir)

            # Move the folder
            old_path = os.path.join(old_solutions_dir, folder)
            new_path = os.path.join(target_dir, folder)
            shutil.move(old_path, new_path)

            print(f"Moved {folder} -> {difficulty}/")

            # Update stats
            stats["solvedSlugs"].append(slug)
            stats["solved"] += 1
            stats[difficulty.lower()] += 1

            # Sleep briefly to avoid LeetCode rate limits
            time.sleep(1)

        except Exception as e:
            print(f"Failed to process {folder}: {e}")

    # Generate stats.json
    stats_path = os.path.join(repo_dir, 'stats.json')
    with open(stats_path, 'w') as f:
        json.dump(stats, f, indent=2)
    
    print("Reorganization complete! stats.json generated.")

if __name__ == "__main__":
    reorganize()
