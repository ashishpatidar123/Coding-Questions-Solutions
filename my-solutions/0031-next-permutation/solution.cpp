class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        bool check = false;
        int index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                check = true;
                break;

            }
        }
        int index2 = -1;
        int mini = INT_MAX;
        if(check){
            for(int i=index+1; i<n; i++){
                if(nums[i] > nums[index]){
                    if(nums[i]<=mini){
                        mini = nums[i];
                        index2 = i;
                    }
                }
            }
            int temp = nums[index];
            nums[index] = nums[index2];
            nums[index2] = temp;

            reverse(nums.begin() + index+1, nums.end());

            return;
        }

        else{
            reverse(nums.begin(),nums.end());
        }
        return;
        
    }
};
