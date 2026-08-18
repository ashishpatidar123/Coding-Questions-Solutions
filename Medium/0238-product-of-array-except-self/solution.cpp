class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        // vector<long long int>prefix(n+1,1);
        // vector<long long int>suffix(n+1,1);

        // for(int i=1; i<n; i++){
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }
        // for(int i=n-2; i>=0; i--){
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }
        int prefix = 1;
        int suffix = 1;

        
        vector<int>ans(n,0);
        ans[0] = 1;
        for(int i=1; i<n; i++){
            ans[i] = prefix*nums[i-1];
            prefix = prefix*nums[i-1];
        }
        for(int i=n-2; i>=0; i--){
            ans[i] = ans[i] * suffix * nums[i+1];
            suffix = suffix * nums[i+1];
        }
        // for(int i=0; i<n; i++){
        //     ans[i] = prefix[i] * suffix[i];
        // }
        
        return ans;

    }
};
