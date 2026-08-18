vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> ans;
    
    // if tree is empty then return empty array
    if(root==NULL){
        return ans;
    }
    // if there is only one node then return the array by pushing that node into it
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->val);
        return ans;
    }
    
    // create a stack
    stack<TreeNode*> st;
    // and a current pointer pointing to the root node
    TreeNode* curr = root;
    
    // we will run the loop untile current is NULL or stack is empty
    while(curr!=NULL || !st.empty()){
        
        // if the current pointer is not null then we will go to its left
        while(curr!=NULL){

            st.push(curr);
            curr = curr->left;
            
        }
        // now if the current pointer is null then
        // pop out the top node from the stack and move to its right(because we already traversed the left part)
        if(curr==NULL){
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        
    }
    return ans;
}
