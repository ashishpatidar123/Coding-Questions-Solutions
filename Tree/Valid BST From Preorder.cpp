int Solution::solve(vector<int> &A) {
    
    stack<int>st;
    int root = INT_MIN;
    for(int i=0; i<A.size(); i++){
        if(A[i]<=root){
            return false;
        }
        while(!st.empty() && A[i]>=st.top()){
            if(A[i]==st.top()){
                return false;
            }
            root = st.top();
            st.pop();
        }
        st.push(A[i]);
    }
    return true;
}
