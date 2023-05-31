class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // initiliase two pointers to index 0
        int i = 0;
        int j = 0;
        // traverse the array 
        for(int j=0; j<nums.size(); j++){
            // if we find an element not equal to the element at the index i 
            // then just add that element at index i+1
            // and increase i by 1
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        // return number of unique elements
        // which is equal to last index(i) + 1
        return i+1;
        
    }
};
