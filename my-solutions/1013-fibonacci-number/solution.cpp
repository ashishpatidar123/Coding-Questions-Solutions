class Solution {
public:
    vector<int> dp;
    const int mod = 1000000007;

    Solution() {
        dp.resize(100001, -1);
    }
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = fib(n-1) + fib(n-2);
    }
};
