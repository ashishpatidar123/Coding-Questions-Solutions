class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n = nums.size();

        int i=0;
        int j=n-1;

        while(i <= j){

            if(nums[i] == val && nums[j] !=  val){
                nums[i] = nums[j];
                nums[j] = val;
                i++;
                j--;
            }
            else if(nums[i] != val && nums[j] == val){
                i++;
                j--;
            }
            else if(nums[i] == val && nums[j] == val){
                j--;
            }
            else{
                i++;
            }

        }
        return i;
        
    }
};
