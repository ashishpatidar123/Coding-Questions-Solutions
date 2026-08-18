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
    int level(TreeNode* root, int temp , int lev){

        if(root==NULL){
            return 0;
        }
        if(root->val==temp){
            return lev;
        }
        int l = level(root->left,temp,lev+1);
        if(l!=0){
            return l;
        }
        return level(root->right,temp,lev+1);

    }
    bool isSiblings(TreeNode* root, int x, int y) {
        if (root == nullptr) {
            return false;
        }
        
        bool foundX = false;
        bool foundY = false;
        
        if (root->left != nullptr && root->right != nullptr) {
            foundX = (root->left->val == x || root->right->val == x);
            foundY = (root->left->val == y || root->right->val == y);
        }
        
        return foundX && foundY ||
            isSiblings(root->left, x, y) ||
            isSiblings(root->right, x, y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {

        
        
        return (level(root,x,1)==level(root,y,1) &&
                !isSiblings(root,x,y));

        
    }
};
