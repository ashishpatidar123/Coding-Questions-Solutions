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
    // create a helper function to find height of the tree
private:
    int height(TreeNode* root){
        // if root is NULL then return 0
        if(root==NULL){
            return 0;
        }
        else{
            // recursively find height of the left and right subtrees
            int leftheight = height(root->left);
            int rightheight = height(root->right);
            // return 1+max of the two heights
            return max(leftheight,rightheight)+1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        
        // if tree is empty then it is always balanced
        if(root==NULL){
            return true;
        }
        // check for the conditions
        return (abs(height(root->left)-height(root->right))<=1)&&isBalanced(root->left)
                    &&isBalanced(root->right);
        
    }
};
