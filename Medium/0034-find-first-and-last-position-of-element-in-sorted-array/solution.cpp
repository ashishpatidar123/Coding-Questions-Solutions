class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        auto it1 = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        auto it2 = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        vector<int>ans;
        if(n==0){
            return {-1,-1};
        }
        else if(it1==n){
            return {-1,-1};
        }
        else if(it1!=n && nums[it1] != target){
            return {-1,-1};
        }
        ans.push_back(it1);
        ans.push_back(it2-1);
        
        return ans;

    }
};
