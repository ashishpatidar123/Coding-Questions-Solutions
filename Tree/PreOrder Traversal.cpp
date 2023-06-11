vector<int> Solution::preorderTraversal(TreeNode* root) {
    
    vector<int> ans;
    // if tree is empty then return null
    if(root==NULL){
        return ans;
    }
    // create a stack and a current pointer intially pointing to the root node
    stack<TreeNode*> st;
    TreeNode* curr = root;
    // run the loop until the stack is empty or the current is null
    while(curr!=NULL || !st.empty()){
        
        // traverse to the left of the node 
        // and push it into the stack before traversing 
        // and since in order the current node is printed before its left and right child
        // so we will push the value of the current node to the ans arraye
        while(curr!=NULL){
            st.push(curr);
            ans.push_back(curr->val);
            curr = curr->left;
        }
        // if current is null then it means left part is done
        // so now pop out the top node from the stack and make current equals to the right of 
        //the top node
        if(curr==NULL){
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
    }
    return ans;
}
