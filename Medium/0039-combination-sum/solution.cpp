class Solution {
private: 
    void solve(vector<int>&candidates,vector<int>&temp,set<vector<int>>&store,int index,int target){

        if(index>=candidates.size()){
            if(target==0){
                store.insert(temp);
            }
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            
            solve(candidates,temp,store,index,target-candidates[index]);
            temp.pop_back();
        }
        solve(candidates,temp,store,index+1,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int index = 0;
        vector<vector<int>> ans;
        set<vector<int>> store;
        sort(candidates.begin(),candidates.end());
        solve(candidates,temp,store,index,target);
        for(auto i:store){
            ans.push_back(i);
        }
        return ans;

    }
};
