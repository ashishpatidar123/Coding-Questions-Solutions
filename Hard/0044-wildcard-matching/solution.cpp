class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int>dpPrev(m+1);
        vector<int>dp(m+1);

        dpPrev[0]= 1;
        bool  flag = true;
        for(int i=1; i<=m; i++){
            if(p[i-1]=='*'){
                dpPrev[i] = dpPrev[i-1];
            }
            else{
                flag = false;
            }
        }
        if(flag==true && n==0){
            return true;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1]){
                    dp[j] = dpPrev[j-1];
                }
                else if(p[j-1]=='?'){
                    dp[j] = dpPrev[j-1];
                }
                else if(p[j-1]=='*'){
                    dp[j] = dpPrev[j] || dp[j-1];
                }
                else{
                    dp[j] = 0;
                }
            }
            dpPrev = dp;
        }
        return dp[m];
    }
};
