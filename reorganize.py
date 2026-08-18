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
    try:
        response = requests.post("https://leetcode.com/graphql", json=query, headers=headers)
        data = response.json()
        return data['data']['question']['difficulty']
    except Exception as e:
        print(f"API Error for {slug}: {e}")
        return None

def reorganize():
    if not os.path.exists(old_solutions_dir):
        print("Error: 'my-solutions' folder not found!")
        return

    # Ignore category folders if they already exist so we don't re-process them
    ignore_dirs = {'Easy', 'Medium', 'Hard'}
    folders = [f for f in os.listdir(old_solutions_dir) 
               if os.path.isdir(os.path.join(old_solutions_dir, f)) and f not in ignore_dirs]
    
    stats = {"solved": 0, "easy": 0, "medium": 0, "hard": 0, "solvedSlugs": []}

    print(f"Found {len(folders)} problem folders to process inside 'my-solutions/'.")

    for folder in folders:
        # 1. Strip leading digits and dash (e.g., "0653-two-sum...")
        clean_name = re.sub(r'^\d+-', '', folder)
        # 2. Strip trailing hyphens
        clean_name = clean_name.rstrip('-')
        # 3. Clean up multiple consecutive hyphens
        slug = re.sub(r'-+', '-', clean_name)

        print(f"Processing: '{folder}' -> Slug: '{slug}'")
        
        try:
            difficulty = get_difficulty(slug)
            
            if not difficulty:
                print(f"Warning: Could not fetch difficulty for {slug}. Skipping.")
                continue

            # Target directory inside my-solutions/Easy, Medium, or Hard
            target_dir = os.path.join(old_solutions_dir, difficulty)

            if not os.path.exists(target_dir):
                os.makedirs(target_dir)

            old_path = os.path.join(old_solutions_dir, folder)
            new_path = os.path.join(target_dir, folder)
            
            if old_path != new_path and not os.path.exists(new_path):
                shutil.move(old_path, new_path)

            print(f"-> Moved to my-solutions/{difficulty}/")

            # Update stats tracking
            if slug not in stats["solvedSlugs"]:
                stats["solvedSlugs"].append(slug)
                stats["solved"] += 1
                stats[difficulty.lower()] += 1

            # Respect LeetCode's rate limits
            time.sleep(1)

        except Exception as e:
            print(f"Failed to process {folder}: {e}")

    # Write the stats.json file into the root directory for your portfolio
    stats_path = os.path.join(repo_dir, 'stats.json')
    with open(stats_path, 'w') as f:
        json.dump(stats, f, indent=2)
    
    print("\nReorganization complete! 'stats.json' successfully generated in root.")

if __name__ == "__main__":
    reorganize()