class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum is strictly to the right of mid
                left = mid + 1;
            } else {
                // Minimum is at mid or to the left
                right = mid;
            }
        }

        return nums[left];
    }
};