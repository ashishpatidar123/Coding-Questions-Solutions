class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        int n = nums.size();
        if(n==1 && target>=0 && abs(nums[0])!=target){
            return 0;
        }
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int sum2 = (sum-target)/2;
        if((sum-target)%2!=0 || sum-target<0){
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum2+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=sum2; i++){
            dp[0][i]=0;
        }
        for(int i=1; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum2; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum2];
    }
};
