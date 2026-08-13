import os
import json
import urllib.request
import urllib.parse
import re

def fetch_leetcode_data():
    # Fetch all 5000+ problems and their tags in one single request
    url = "https://leetcode.com/graphql"
    query = """
    query problemsetQuestionList {
      problemsetQuestionList: questionList(categorySlug: "", limit: 5000, skip: 0, filters: {}) {
        questions: data {
          title
          titleSlug
          topicTags { name }
        }
      }
    }
    """
    req = urllib.request.Request(
        url, 
        data=json.dumps({"query": query}).encode("utf-8"), 
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
        }
    )
    response = urllib.request.urlopen(req)
    data = json.loads(response.read())
    return {q['titleSlug']: q for q in data['data']['problemsetQuestionList']['questions']}

def generate_readme():
    print("Fetching problems from LeetCode API...")
    leetcode_data = fetch_leetcode_data()
    
    topics = {}
    target_dir = 'my-solutions'
    
    if not os.path.exists(target_dir):
        print(f"Directory '{target_dir}' not found in root!")
        return

    # Scan the my-solutions folder
    for item in os.listdir(target_dir):
        item_path = os.path.join(target_dir, item)
        if not os.path.isdir(item_path) or item.startswith('.'):
            continue
            
        folder_name = item
        slug = folder_name
        
        # Strip LeetHub's numbered prefix if it exists (e.g., "0001-two-sum" -> "two-sum")
        match = re.match(r'^\d+-(.+)$', folder_name)
        if match:
            slug = match.group(1)
            
        if slug in leetcode_data:
            problem = leetcode_data[slug]
            tags = problem['topicTags']
            
            if not tags:
                topics.setdefault("Uncategorized", []).append((problem['title'], folder_name))
            
            for tag in tags:
                topics.setdefault(tag['name'], []).append((problem['title'], folder_name))

    # Generate the README text
    with open('README.md', 'w', encoding='utf-8') as f:
        f.write("# 🧑‍💻 My LeetCode Solutions\n\n")
        f.write("This repository contains my algorithmic solutions, automatically organized by topic.\n\n")
        
        for topic in sorted(topics.keys()):
            f.write(f"## {topic}\n")
            for title, folder_name in sorted(topics[topic]):
                # Generate relative path to the subfolder
                safe_folder = urllib.parse.quote(folder_name)
                f.write(f"- [{title}](./{target_dir}/{safe_folder})\n")
            f.write("\n")
            
    print("README.md generated successfully!")

if __name__ == "__main__":
    generate_readme()
