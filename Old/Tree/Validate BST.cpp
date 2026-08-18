class Solution {
private:
    int min(TreeNode*root){
        // finding the minimum node
        while(root->left!=NULL){
            root = root->left;
        }
        return root->val;
    }
    int max(TreeNode*root){
        //finding the maximum node
        while(root->right!=NULL){
            root = root->right;
        }
        return root->val;
    }
public:
    bool isValidBST(TreeNode* root) {
        
        // if root is null then return true
        if(root==NULL){
            return true;
        }
        // check for the basic bst conditions
        if(root->left!=NULL){
            if(root->left->val >= root->val||max(root->left)>=root->val)
            {
                return false;
            }
        }
        // check for the basic bst conditions
        if(root->right!=NULL){
            if(root->right->val <= root->val
                ||min(root->right)<=root->val)
            {
                return false;
            }
        }
        // check for the left and right half
        return isValidBST(root->left)&&isValidBST(root->right);
        
    }
};
