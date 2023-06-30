class Solution {
    int solve(vector<int>&nums,int n, int sum, vector<vector<int>>&dp){
        // base case 
        // if sum is 0 then we can always have a empty subset
        if(sum==0){
            return 1;
        }
        // if n is 0 and sum is not zero
        // then we cannot have a subset with some nonzero sum 
        if(n==0){
            return 0;
        }
        // if we already calculated a value then return it
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        // else check if the element is less than or equal to sum 
        if(nums[n-1]<=sum){
            // if it is then either we can include it or exclude it
            return dp[n][sum] = solve(nums,n-1,sum-nums[n-1],dp)||solve(nums,n-1,sum,dp);
        }
        // else we can't include it so we have to exclude it
        else{
            return dp[n][sum] = solve(nums,n-1,sum,dp);
        }

    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        sum = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

        if(solve(nums,n,sum,dp)){
            return true;
        }
        return false;
    }
};
