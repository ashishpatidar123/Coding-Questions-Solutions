class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        // declare a vector ans
        vector<int> ans;
        // declare a vector temp of double the size than nums
        vector<int> temp(2*nums.size(),0);
        

        int n = nums.size();
        
        // fill the temp with nums two times
        // so that we can form a circular loop
        for(int i=0; i<nums.size(); i++){
            temp[i] = nums[i];
            temp[nums.size()+i] = nums[i];
        }
        
        // declare a stack
        stack<int> st;
        
        // traverse from the back
        // since we added nums two times in temp
        // so we only put answer to our ans vector for values of i less than i
        // because we don't want to waste memory two times
        for(int i = 2*n-1; i>=0; i--){
            
            // if the stack is empty 
            // push the index inside the stack
            // and push -1 into the answer array because stack is empty(if i is less
            // than n)
            if(st.empty()){
                st.push(i);
                if(i<n){
                    ans.push_back(-1);
                }
            }

            // check for the empty stack and if the element at the top of the stack
            // is smaller or equal to the current element
            // if yes then pop it out
            while(!st.empty() && temp[i]>=temp[st.top()]){
                st.pop();
            }
            
            // if the stack is empty then push -1 (if i is less than n)
            // push the index into the stack
            if(st.empty()){
                if(i<n){
                    ans.push_back(-1);
                }
                st.push(i);
            }

            // else push element at the top index to the array(if it is less than n)
            // push the index into the stack
            else{
                if(i<n){
                    ans.push_back(temp[st.top()]);
                }
                
                st.push(i);
            }
        }
        // reverse the answer array
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
