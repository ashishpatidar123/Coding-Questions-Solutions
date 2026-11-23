class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        
        int prev1 = 0;
        int prev2 = 0;
        

        for(int i=end; i>=start; i--){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        int first = solve(nums, 0, n-2);
        int second = solve(nums, 1, n-1);

        return max(first, second);
    }
};