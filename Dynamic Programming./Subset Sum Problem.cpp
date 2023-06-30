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
