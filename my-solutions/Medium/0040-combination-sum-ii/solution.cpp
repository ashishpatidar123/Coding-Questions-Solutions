// class Solution {
// private: 
//     void solve(vector<int>&candidates,vector<int>&temp,set<vector<int>>&store,int index,int target){

//     if(index>=candidates.size()){
//         if(target==0){
//             store.insert(temp);
//         }
//         return;
//     }
//     if(candidates[index]<=target){
//         temp.push_back(candidates[index]);
//         solve(candidates,temp,store,index+1,target-candidates[index]);
//         temp.pop_back();
//     }
//     solve(candidates,temp,store,index+1,target);
// }

// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//     vector<int> temp;
//     int index = 0;
//     vector<vector<int>> ans;
//     set<vector<int>> store;
//     sort(candidates.begin(),candidates.end());
//     solve(candidates,temp,store,index,target);
//     for(auto i:store){
//         ans.push_back(i);
//     }
//     return ans;
// }
// };
class Solution {
public:
    vector<vector<int>> result;
    
    void comsum(vector<int> &curr, int target, int sum, vector<int> &candidates, int curInd, int n){
        if(target == sum){
            result.push_back(curr);
            return;
        }
        else if(sum>target){
            return;
        }
        
        for(int i = curInd; i < n; i++){
            if(i != curInd && candidates[i]==candidates[i-1])               //to avoid picking up the same combnations i.e. we don't pick same element for certain kth position of a combination 
                continue;
            sum += candidates[i];
            curr.push_back(candidates[i]);
            comsum(curr, target, sum, candidates, i+1, n);
            sum -= candidates[i];
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        comsum(curr, target, 0, candidates, 0, n);
        return result;
    }
};
