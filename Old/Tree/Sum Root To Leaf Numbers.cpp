int findsum(vector<int> path){
    int temp = 0;
    for(int i=0; i<path.size(); i++){
        temp = (10*temp + path[i])%1003;
    }
    return temp;
}
void solve(TreeNode *root, int &sum, vector<int> path){
    if(root==NULL){
        return;
    }
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        sum = (sum + findsum(path))%1003;
        return;
    }
    solve(root->left,sum,path);
    solve(root->right,sum,path);
}
int Solution::sumNumbers(TreeNode* root) {
    vector<int> path;
    int sum = 0;
    solve(root,sum,path);
    return sum;
}
