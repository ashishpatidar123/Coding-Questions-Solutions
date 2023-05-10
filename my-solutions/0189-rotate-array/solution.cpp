class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            ans[i] = nums[i];
        }
        int j=0;
        for(int i=(n-k%nums.size())%nums.size(); i<nums.size(); i++){
            nums[j++] = ans[i];
        }
        for(int i=0; i<(n-k%nums.size())%nums.size(); i++){
            nums[j++] = ans[i];
        }

    }
};
