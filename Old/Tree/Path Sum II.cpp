// https://chat.openai.com/share/7ac9be5c-8217-4554-9648-2b550b334b4d
void solve(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& ans) {
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }
    
    // Add the current node's value to the path
    path.push_back(root->val);
    
    // Check if the current node is a leaf node and its value equals the target sum
    if (root->val == sum && root->left == NULL && root->right == NULL) {
        ans.push_back(path); // Add the current path to the answer
        return;
    }
    
    // Recursively explore the left and right subtrees
    solve(root->left, sum - root->val, path, ans);
    solve(root->right, sum - root->val, path, ans);
}

// The solve function performs a depth-first search (DFS) on the binary tree 
// to find all paths with the desired sum. It takes the following parameters:
   // root: A pointer to the current node being processed.
   // sum: The remaining sum to reach the target.
   // path: A vector that stores the current path from the root to the current node.
   // ans: A reference to the vector of vectors that will store the resulting paths.
// The function starts with a base case: if the current node is NULL, it returns immediately since there are no more nodes to process.
// Next, it adds the current node's value to the path vector.
// Then, it checks if the current node is a leaf node (i.e., both left and right children are NULL) and if its value equals the target sum.
// If this condition is true, it means we have found a valid path that adds up to the target sum
// 
