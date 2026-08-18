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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        int leftdepth = INT_MAX;
        int rightdepth = INT_MAX;

        if(root->left!=NULL){
            leftdepth = minDepth(root->left);
        }

        if(root->right!=NULL){
            rightdepth = minDepth(root->right);
        }

        return min(leftdepth,rightdepth)+1;
        
    }
};
