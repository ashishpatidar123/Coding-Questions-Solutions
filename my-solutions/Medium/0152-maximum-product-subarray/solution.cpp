class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int curMax = nums[0], curMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int temp = curMax;
            curMax = max({nums[i], curMax * nums[i], curMin * nums[i]});
            curMin = min({nums[i], temp * nums[i], curMin * nums[i]});
            ans = max(ans, curMax);
        }

        return ans;
    }
};

