class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long mini = -1e15;

        long long dp0 = mini;
        long long dp1 = mini;
        long long dp2 = mini;
        long long dp3 = mini;

        long long maxi = mini;

        for(int i=0; i<n; i++){
            long long val = (long long) nums[i];

            long long mul = val * k;
            long long div = val/k;


            long long dp0_prev = dp0;
            long long dp1_prev = dp1;
            long long dp2_prev = dp2;
            long long dp3_prev = dp3;


            dp0 = max(val, dp0_prev + val);

            dp1 = max({mul, dp0_prev + mul, dp1_prev + mul});

            dp2 = max({div, dp0_prev + div, dp2_prev + div});

            dp3 = max({dp3_prev + val, dp1_prev + val, dp2_prev + val});
            
            maxi = max({maxi, dp1, dp2, dp3});

        }
        return maxi;
    }
};
