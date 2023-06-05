class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {   
        // declare a stack
        stack<int> st;
        // declare a answer vector
        vector<int> ans;
        
        // push -1 in ans because for the last index there are no elements in the right
        ans.push_back(-1);
        // push the last index into the stack
        st.push(n-1);
        
        // traverse from the backside
        for(int i=n-2; i>=0; i--){
            // check for the empty condition
            // and push index into the stack and -1 in ans
            if(st.empty()){
                st.push(i);
                ans.push_back(-1);
            }
            // if the stack is not empty then pop all the greater or equal elements from it
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            // now if the stack is empty 
            // push the index into the stack and -1 in ans
            if(st.empty()){
                st.push(i);
                ans.push_back(-1);
            }
            // else push the element at the top index to ans
            // and push the index into the stack
            else{
                ans.push_back(arr[st.top()]);
                st.push(i);
            }
            
        }
        // reverse ans
        reverse(ans.begin(),ans.end());
        return ans;
        
        } 
};
