class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int len = INT_MAX;
        int l = 0;
        int r = 0;
        int sum = 0;

        while(r < n){
            sum += nums[r];

            while(l <= r && sum >= target){
                if(r-l+1 < len){
                    len = r-l+1;
                }

                sum -= nums[l];

                l++;
            } 
            r++;
        }

        if(len == INT_MAX) return 0;

        return len;
        
    }
};
