class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // sort(nums.begin(),nums.end());
        // int count = 0;
        // int index = 0;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i]==val){
        //         count++;
        //     }

        // }
        // for(int i =0; i<nums.size(); i++){
        //     if(nums[i]==val){
        //         index = i;
        //         break;
        //     }
        // }
        // int j = index + count;
        // for(int i=j; i<nums.size(); i++){
        //     swap(nums[i],nums[index++]);
        // }
        // return index;
        int i=0;
        int j=0;
        while(j<nums.size()){
            
            if(nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==val){
                j++;
            }
        }
        return i;
    }
};
