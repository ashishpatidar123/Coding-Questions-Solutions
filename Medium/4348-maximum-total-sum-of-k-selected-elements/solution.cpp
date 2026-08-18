class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        
        int n = nums.size();
        long long total = 0;

        sort(nums.begin(), nums.end());

        int index = n-1;

        while(k > 0){
            int val = nums[index];
            index--;

            if(mul > 0){
                total += (long long)mul * (long long)val;
            }
            else{
                total += val;
            }

            mul--;
            k--;

        }

        return total;
    }
};
