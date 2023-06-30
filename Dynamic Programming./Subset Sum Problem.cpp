//tabulation approach
int Solution::solve(vector<int> &A, int B) {
    int n1 = A.size();
    vector<vector<int>>dp(n1+1,vector<int>(B+1,0));
    for(int i=0; i<=n1; i++){
        dp[i][0]=1;
    }
    for(int i=1; i<=B; i++){
        dp[0][i]=0;
    }
    for(int i=1; i<=n1; i++){
        for(int j=0; j<=B; j++){
            if(A[i-1]<=j){
                dp[i][j]=dp[i-1][j-A[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n1][B];
}
// memoisation approach
class Solution{  
    int solve(vector<int>&arr,int sum, int n, vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            return dp[n][sum] = solve(arr,sum-arr[n-1],n-1,dp)||solve(arr,sum,n-1,dp);
        }
        else{
            return dp[n][sum] = solve(arr,sum,n-1,dp);
        }
        return dp[n][sum];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,n,dp);
    }
};
