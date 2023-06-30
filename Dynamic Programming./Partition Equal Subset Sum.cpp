// tabulation approach
class Solution{
    
public:
    int equalPartition(int N, int nums[])
    {
        int n = N;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        if(sum%2!=0){
            return 0;
        }
        sum = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        // intialising the dp
        // for the cases when the sum is 0 we always get a subset hence the value is 1
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        // for the case when n is 0 we can't get any subset hence the value is 0
        for(int j=1; j<=sum; j++){
            dp[0][j]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
// memoization approach
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
