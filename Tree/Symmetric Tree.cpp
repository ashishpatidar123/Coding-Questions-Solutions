bool ismirror(TreeNode*A, TreeNode* B){
    if(A==NULL && B==NULL){
        return 1;
    }
    if(A==NULL || B==NULL){
        return 0;
    }
    
    return (A->val==B->val && ismirror(A->left,B->right) && ismirror(A->right,B->left));
}

int Solution::isSymmetric(TreeNode* A) {
    // if the tree is empty then it is symmetric
    if(A==NULL){
        return 1;
    }
    // now check is the left subtree and righttree are mirror images of each other or not
    int check = ismirror(A->left,A->right);
    
    return check;
    
}
