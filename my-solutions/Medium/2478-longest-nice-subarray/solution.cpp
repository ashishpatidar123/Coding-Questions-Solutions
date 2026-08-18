class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();

        int l = 0;
        int mask = 0;
        int ans=  1;

        for(int r=0; r<n; r++){

            int an = mask & nums[r];

            while(an != 0){
                mask = mask ^ nums[l];
                an = mask & nums[r];
                l++;
            }

            mask = mask | nums[r];

            ans = max(ans, r-l+1);
        }

        return ans;

        
    }
};
