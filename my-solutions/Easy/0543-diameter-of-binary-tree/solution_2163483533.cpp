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
    int maxi = -1;
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        int depth1 = dfs(node->left);
        int depth2 = dfs(node-> right);

        maxi = max(maxi, depth1 + depth2);
        return 1+max(depth1, depth2);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        

        if(!root){
            return 0;
        }

        int diameter = dfs(root);
        
        return maxi;
        
    }
};