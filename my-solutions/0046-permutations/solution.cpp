class Solution {
    void generate(vector<int>nums, vector<vector<int>>&ans, int index){

        if(index>=nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int j=index; j<nums.size(); j++){
            swap(nums[j],nums[index]);
            generate(nums,ans,index+1);
            swap(nums[j],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int index = 0;
        generate(nums,ans,index);
        return ans;
        
        
    }
};
