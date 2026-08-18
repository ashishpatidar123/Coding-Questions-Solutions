class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){

            if(sum + nums[i] >= 0){
                sum += nums[i];
                maxi = max(maxi,sum);
            }
            else{
                sum += nums[i];
                maxi = max(maxi,sum);
                sum = 0;
            }

        }
        return maxi;
        
    }
};
