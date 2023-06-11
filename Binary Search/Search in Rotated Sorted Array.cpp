class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right){
            int mid = (left+right)/2;
          
            // If the target value is equal to the value at the middle index (nums[mid]),
            // we have found the target in the array, and we return the index mid.
            if(target == nums[mid]){
                return mid;
            }
            // If the leftmost value (nums[left]) is less than or equal to the middle value (nums[mid]), 
            // it means that the left half of the array is sorted in ascending order. 
            // In this case, we perform a sub-check:
              // If the target is less than the leftmost value or greater than the middle value, 
              // it means the target is not present in the left half. 
              // So, we update left to mid + 1, indicating that we should search in the right half.
              
              // Otherwise, if the target is within the range of the left half, 
              // we update right to mid - 1, indicating that we should search in the left half.
            if(nums[left]<=nums[mid]){
                if((nums[left]>target)||(target>nums[mid])){
                     left = mid+1;
                }
              
                else{
                    right = mid-1;
                }
            }
            // If the leftmost value is greater than the middle value, 
            // it means that the right half of the array is sorted in ascending order. 
            // In this case, we perform a sub-check:
               // If the target is greater than the rightmost value or less than the middle value, 
               // it means the target is not present in the right half. 
               // So, we update right to mid - 1, indicating that we should search in the left half
              
               // Otherwise, if the target is within the range of the right half, 
               // we update left to mid + 1, indicating that we should search in the right half.
            else {
                if((nums[right]<target)||(target<nums[mid])){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }

            }
        }
        // If the target value is not found in the array, 
        // we continue the loop until left becomes greater than right, 
        // indicating that the target is not present. In that case, we return -1.
        return -1;

    }
};

