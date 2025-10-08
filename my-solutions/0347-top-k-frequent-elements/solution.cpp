class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int,int>count;

        for(int i=0; i<n; i++){
            count[nums[i]]++;
        }
        vector<pair<int,int>>temp;

        for(auto it:count){
            int key = it.first;
            int value = it.second;

            temp.push_back({value, key});
        }
        sort(temp.begin(),temp.end(),[](pair<int,int> &a, 
            pair<int,int>&b){
                return a.first > b.first;
            });
        vector<int>ans;

        for(int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        return ans;

    }
};
