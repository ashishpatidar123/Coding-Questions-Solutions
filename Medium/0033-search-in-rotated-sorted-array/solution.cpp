class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(end>=start){

            int mid = start + (end-start)/2;

            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[start]){
                if(nums[start] <= target && nums[mid] >= target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
                
            }
            else if(nums[mid] < nums[start]){
                if(nums[mid] <= target && nums[end] >= target){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }

        }
        return -1;
    }
};
