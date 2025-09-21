class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = sizeof(nums)/sizeof(nums[0]);
        int m = nums.size();
        int i=0;
        int idx = i+1;
        int j=i+1;

        while(j<m){

            if(nums[i]==nums[j]){
                j++;
            }
            else{
                nums[idx]=nums[j];
                j++;
                i = idx;
                idx++;
            }

        }
        return idx;
    }
};
