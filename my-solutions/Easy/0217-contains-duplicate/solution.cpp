class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int,int> count;
        for(auto num : nums){

            count[num]++;

        }
        for(auto it:count){
            if(it.second > 1){
                return true;
            }
        }
        return false;

    }
};
