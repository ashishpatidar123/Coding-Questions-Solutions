class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 0;
       
        for(int i=1; i<=n; i++){
            int x = s1[i-1];
            dp[i][0] = dp[i-1][0] + x;
        }
        for(int i=1; i<=m; i++){
            int x = s2[i-1];
            dp[0][i] = dp[0][i-1] + x;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int x = s1[i-1];
                    int y = s2[j-1];
                    dp[i][j] = min(x+ dp[i-1][j], y + dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
