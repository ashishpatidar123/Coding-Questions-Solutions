class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();

        int sum = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                sum+=1;
            }
            else{
                ans = max(ans, sum);
                sum = 0;
            }
        }
        if(sum!=0){
            ans = max(ans, sum);
        }
        return ans;
    }
};
