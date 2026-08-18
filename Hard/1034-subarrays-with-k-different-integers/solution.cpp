class Solution {
public:
// counting the subarrays with distict elements equal to K or less
    int solve(vector<int>&nums, int k){
        int n = nums.size();
        int count = k;
        int ans = 0;
        
        unordered_map<int,int>freq;

        int l = 0;
        int distinct = 0;

        for(int r = 0; r<n; r++){
            freq[nums[r]]++;
            if(freq[nums[r]] == 1){
                distinct++;
            }

            while(distinct > count){

                freq[nums[l]]--;

                if(freq[nums[l]] == 0){
                    distinct--;
                
                }
                l++;
    
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int ans = solve(nums, k) - solve(nums, k-1);
        return ans;
        
    }
};
