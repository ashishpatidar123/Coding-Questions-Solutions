TreeNode* solve(vector<int> &A, vector<int> &B, int start, int end, int &index, unordered_map<int,int> &find){
    if(index<0 || start>end){
        return NULL;
    }
    TreeNode*root = new TreeNode(B[index--]);
    int i = find[root->val];
    //in this case we create the right subtree first because we're getting right subtree nodes first in
    // postorder traversal
    root->right = solve(A,B,i+1,end,index,find);
    root->left = solve(A,B,start,i-1,index,find);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int start = 0;
    int end = A.size()-1;
    int index = end;
    
    unordered_map<int,int> find;
    
    for(int i=0; i<=end; i++){
        find[A[i]] = i;
    }
    
    return solve(A,B,start,end,index,find);
}
