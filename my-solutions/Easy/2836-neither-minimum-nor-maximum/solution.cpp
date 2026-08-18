class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        
        int maxi = INT_MIN;;
        int mini = INT_MAX;
        int n = nums.size();
        int ans = -1;
        if(n<=2){
            return -1;
        }
        for(int i=0; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            if(nums[i] < mini){
                mini = nums[i];
            }
            
        }
        bool check = false;
        for(int i=0; i<n; i++){
            if(nums[i]!=maxi && nums[i]!=mini){
                check = true;
                ans = nums[i];
            }
        }

        if(check){
            return ans;
        }
        else return -1;

        return ans;
    }
};
