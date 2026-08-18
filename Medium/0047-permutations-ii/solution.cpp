class Solution {
    void generate(vector<int> &nums, map<vector<int>,int> &m, int index){
        if(index>=nums.size()-1){
            m[nums]++;
            return;
        }
        for(int j= index; j<nums.size(); j++){
            swap(nums[index],nums[j]);
            generate(nums,m,index+1);
            swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        map<vector<int>,int> m;
        int index = 0;
        generate(nums,m,index);
        for(auto it:m){
            ans.push_back(it.first);
        }
        return ans;
        
    }
};
