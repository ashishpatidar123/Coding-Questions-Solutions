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
    bool pathSum(TreeNode* root, int Sum){
        if(root==NULL){
            return false;
        }
        bool ans = false;
        int subsum = Sum - root->val;
        
        if(subsum==0 && root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->left){
            ans = ans || pathSum(root->left,subsum);
        }
        if(root->right){
            ans = ans || pathSum(root->right,subsum);
        }
        return ans;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        
        return pathSum(root,targetSum);
    }
};
