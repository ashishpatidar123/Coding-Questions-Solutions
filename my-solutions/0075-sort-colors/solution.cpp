class Solution {
public:
    void sortColors(vector<int>& nums) {
    
    int i=0;
    int j=0;

    while(j<nums.size()){

        if(nums[i]>nums[j]){
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
        else if(nums[i]==nums[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    i=0;
    j=0;
    while(j<nums.size()){

        if(nums[i]>nums[j]){
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
        else if(nums[i]==nums[j]){
            j++;
        }
        else{
            i=j;
            j++;
        }
    }
    
    }
};
