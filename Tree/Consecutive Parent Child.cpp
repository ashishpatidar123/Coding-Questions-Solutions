void solve(TreeNode* root, int &count){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL && abs(root->val - root->left->val) ==1){
        
        count++;
        
    }
    if(root->right!=NULL && abs(root->val-root->right->val) == 1){
        count++;
        
    }
    solve(root->left,count);
    solve(root->right,count);
    
}
int Solution::consecutiveNodes(TreeNode* A) {
    int count = 0;
    solve(A,count);
    return count;
}
