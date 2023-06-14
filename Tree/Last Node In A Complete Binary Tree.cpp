int height(TreeNode* root){
    if(!root) 
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int Solution::lastNode(TreeNode* A) {
    
    if(!A->left and !A->right) {
        return A->val;
    }
    int lHeight = height(A->left);
    int rHeight = height(A->right);

    if(lHeight > rHeight)
        return lastNode(A->left);
    return lastNode(A->right);
    
}
