class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==1){
            return 1;
        }
        int i=0; 
        int j = 0;
        int count = 1;

        while(j<nums.size()){

            count = 1;

            while(j+1 < nums.size() && nums[j] == nums[j+1]){
                count++;
                j++;
            }

            int k = min(2,count);
            for(int x = 0; x<k; x++){
                nums[i++] = nums[j];
            }

            j++;
        }
        return i;

        
    }
};
