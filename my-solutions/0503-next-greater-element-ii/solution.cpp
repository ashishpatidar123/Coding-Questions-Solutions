class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        vector<int> ans1;
        stack<int> s;
        vector<int> main;
        int n = nums.size();
        for(int i=0; i<2*n; i++ ){
            if(i<n){
                main.push_back(nums[i]);
            }
            else if(i>=n){
                main.push_back(nums[i-n]);
            }
        }
        for(int j=main.size()-1; j>=0; j--)
        {
            
            while(s.empty()!=1&&main[s.top()]<=main[j]){
                    s.pop();
            }
                    
            if(s.empty()){
                ans.push_back(-1);
            }             
                    
            else{
                ans.push_back(main[s.top()]);
            }
                    
            s.push(j); 
        }
        for(int i=2*n-1; i>=n; i--){
             ans1.push_back(ans[i]);
        }
    return ans1;  
    }
};
