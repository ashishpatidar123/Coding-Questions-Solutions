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
private:
    int min(TreeNode*root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root->val;
    }
    int max(TreeNode*root){
        while(root->right!=NULL){
            root = root->right;
        }
        return root->val;
    }
public:
    bool isValidBST(TreeNode* root) {

        if(root==NULL){
            return true;
        }
        
        if(root->left!=NULL){
            if(root->left->val >= root->val||max(root->left)>=root->val)
            {
                return false;
            }
        }
        if(root->right!=NULL){
            if(root->right->val <= root->val
                ||min(root->right)<=root->val)
            {
                return false;
            }
        }
        return isValidBST(root->left)&&isValidBST(root->right);
        
    }
};
