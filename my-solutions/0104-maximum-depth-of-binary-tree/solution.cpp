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
public:
    int func(TreeNode* root){

        if(root == NULL){
            return 0;
        }
        else return 1+ max(func(root->left), func(root->right));

    }
    int maxDepth(TreeNode* root) {
        
        int ans = func(root);
        return ans;
    }
};
