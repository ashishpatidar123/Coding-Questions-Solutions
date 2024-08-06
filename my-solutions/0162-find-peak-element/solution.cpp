class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();

        int left = 0;
        int right = n-1;
        
        if(n==1){
            return 0;
        }
        if(n==2 && nums[n-1]>nums[n-2] ){
            return 1;
        }
        if(n==2 && nums[n-1]<nums[n-2]){
            return 0;
        }
        while(left+1<right){
            int mid = left + (right-left)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        
        if(right>0 && nums[right-1]>nums[right]){
            return right-1;
        }
        return right;

    }
};
