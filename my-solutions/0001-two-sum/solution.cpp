class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int check = target - nums[i];
            auto it = m.find(check);
            if(it!=m.end()){
                if(it->second!=i){
                    ans.push_back(i);
                    ans.push_back(it->second);
                    return ans;
                }
            }
        }
        return ans;
    }
};
