TreeNode* solve(vector<int> &A, vector<int> &B, int &index, int start, int end,unordered_map<int,int>&m){
    // if the index is greater than the number of elements or our start overtakes end then return null
    if(index>=B.size() || start>end){
        return NULL;
    }
    
    // create a root node from the preorder traversa
    TreeNode* root = new TreeNode(A[index++]);
    // find the index corresponding to this node in preorder traversal
    int i = m[root->val];
    // call for creating left subtree and right subtree
    root->left = solve(A,B,index,start,i-1,m);
    root->right = solve(A,B,index,i+1,end,m);
    // return final root node
    return root;
    
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int start = 0;
    int end = A.size()-1;
    int index = 0;
    // creating a map to store the indexex of the elements in inorder traversal
    unordered_map<int,int> m;
    for(int i=0; i<=end; i++){
        m[B[i]] = i;
    }
    TreeNode* root = solve(A,B,index,start,end,m);
    return root;
}
