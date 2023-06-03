class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        // declare stack 
        stack<int> st;
        
        // declare vector ans;
        vector<long long > ans;
        
        // for the last element push -1 
        ans.push_back(-1);
        
        // push the last index inside 
        st.push(n-1);
        
        // traverse the array from back
        for(int i=n-2; i>=0; i--){
            
            // if the stack is empty 
            // push the index inside the stack
            // and push -1 into the answer array because stack is empty
            if(st.empty()){
                ans.push_back(-1);
                st.push(i);
            }
            
            // check for the empty stack and if the element at the top of the stack
            // is smaller or equal to the current element
            // if yes then pop it out
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            
            // if the stack is empty then push -1 
            // push the index into the stack
            if(st.empty()){
                ans.push_back(-1);
                st.push(i);
            }
            
            // else push element at the top index to the array
            // push the index into the stack
            else{
                ans.push_back(arr[st.top()]);
                st.push(i);
            }
            
            
        }
        // reverse the answer array
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
