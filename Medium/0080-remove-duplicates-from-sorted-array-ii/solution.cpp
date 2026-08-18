class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        
        int m = nums.size();
        if(m<=2) return m;
        int i=0;
        int idx = i+2;
        int j=i+2;

        while(j<m){

            if(nums[j]!=nums[idx-2]){
                nums[idx] = nums[j];
                idx++;
                j++;
            }
            else{
                j++;
            }

        }
        return idx;
    }
};
