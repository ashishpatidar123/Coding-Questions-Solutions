class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;

        vector<int>dp(n+1,0);
        vector<int>dp2(n+1,20000);
        int curr_max = 0;
        int curr_min = 20000;
        int maxi = 0;
        int mini = 20000;

        for(int i=0; i<n; i++){
            curr_max = max(nums[i], nums[i] + curr_max);
            curr_min = min(nums[i], nums[i] + curr_min);
            maxi = max(maxi, curr_max);
            mini = min(mini, curr_min);

        }

        // int ans = INT_MIN;
        // int ans2 = INT_MAX;
        // for(int i=0; i<n+1; i++){
        //     ans = max(ans, dp[i]);
        //     ans2 = min(ans2, dp2[i]);
        // }
        return max(abs(maxi), abs(mini));



    }
};
