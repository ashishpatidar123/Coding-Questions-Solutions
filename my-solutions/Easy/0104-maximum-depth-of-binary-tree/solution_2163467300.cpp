/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        return 1 + max(dfs(node->left), dfs(node->right));
    }
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;

        if(!root){
            return depth;
        }

        depth = dfs(root);

        return depth;
        
    }
};