vector<int> Solution::prevSmaller(vector<int> &A) {

    stack<int> st;
    vector<int> ans;
    // for the first element there are no elements on the left so push -1 in ans
    ans.push_back(-1);
    // push the index zero into the stack
    st.push(0);
    int n = A.size();
    // traverse from the second element
    for(int i=1; i<n; i++){
        // if we get stack as empty then
        // push the index into the stack and
        // push -1 in ans because there is no smaller element in the left for the given element
        if(st.empty()){
            st.push(i);
            ans.push_back(-1);
        }
        // now if stack is not empty
        // pop all the greater elements than the current element from the stack
        while(!st.empty() && A[st.top()]>=A[i]){
            st.pop();
        }
        // now after popping if the stack is empty then
        // push index into the stack and -1 in ans(same reason as above if condition)
        if(st.empty()){
            st.push(i);
            ans.push_back(-1);
        }
        // else we find the smaller element in the stack
        // then push that element to our ans 
        // and push the index of the current element to the stack
        else{
            ans.push_back(A[st.top()]);
            st.push(i);
        }
        
    }
    
    return ans;
}
