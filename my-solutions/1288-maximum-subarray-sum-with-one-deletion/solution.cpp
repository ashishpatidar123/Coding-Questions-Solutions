class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        long long dp0 = -1e15;
        long long dp1 = -1e15;

        long long max_sum = -1e15;

        for(int i=0; i<n; i++){
            long long val = (long long) arr[i];

            long long prev_dp0 = dp0;
            long long prev_dp1 = dp1;

            dp0 = max(prev_dp0 + val, val);
            dp1 = max({prev_dp1 + val, prev_dp0});

            max_sum = max({max_sum, dp0, dp1});
        }
        return max_sum;
    }
};
