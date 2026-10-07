class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<int>dp(amount+1,INT_MAX-1 );
        dp[0] = 0;

        for(int i=0; i<n; i++){
            for(int x=coins[i]; x<=amount; x++){
                dp[x] = min(dp[x], 1 + dp[x-coins[i]]);
            }
        }
        if(dp[amount] == INT_MAX-1) return -1;
        return dp[amount];
        
    }
};