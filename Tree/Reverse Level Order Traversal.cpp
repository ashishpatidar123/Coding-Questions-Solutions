vector<int> Solution::solve(TreeNode* root) {
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    //create a stack and a queue
    stack<TreeNode*>st;
    queue<TreeNode*>q;
    // push the root node into the queue
    q.push(root);
    TreeNode* curr = NULL;
    // run the loop until q is empty
    while(!q.empty()){
        
        // set current equal to the front element of the queue
        // and pop it
        curr = q.front();
        
        // push the current node to the stack
        st.push(curr);
        q.pop();
        
        // push the right first since we're doing reverse so when producing output we will get left first
        if(curr->right){
            q.push(curr->right);
        }
        //now push left
        if(curr->left){
            q.push(curr->left);
        }
    }
    // push all the stack nodes to our ans vector
    while(!st.empty()){
        ans.push_back(st.top()->val);
        st.pop();
    }
    return ans;
}
