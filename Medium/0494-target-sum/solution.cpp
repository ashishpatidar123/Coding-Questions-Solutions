class Solution {
public:
    int ans = 0;
    void func(vector<int>&nums, int sum,  int n, int i, int target){
        if(i == n){
            if(sum == target){
                ans++;
               
            }
            return;
        }
        func(nums, sum + nums[i], n, i+1, target);
        func(nums, sum-nums[i], n, i+1, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        // func(nums, 0, n, 0, target);
        // return ans;
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        if(abs(target) > total) return 0;
        // vector<vector<int>>dp(n+1, vector<int>(2*total+1,0));

        // dp[0][total] = 1;

        // for(int i=0; i<n; i++){
        //     for(int s=0; s<=2*total; s++){
        //         if(dp[i][s] > 0){
        //             dp[i+1][s + nums[i]] += dp[i][s];
        //             dp[i+1][s - nums[i]] += dp[i][s];
        //         }
        //     }
            

        // }

        // return dp[n][target + total];

        vector<int>dp(2*total+1,0);
        dp[total]=1;

        for(int i = 0; i < n; i++) {
        vector<int> next(2 * total + 1, 0); // Temporary storage for current element
        for(int s = 0; s <= 2 * total; s++) {
            if(dp[s] > 0) {
                next[s + nums[i]] += dp[s];
                next[s - nums[i]] += dp[s];
            }
        }
        dp = next; // Update the main DP table for the next iteration
    }
        return dp[total+target];

    }
};
