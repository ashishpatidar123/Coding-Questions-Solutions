class Solution {
private:
    void solve(vector<int>&num,vector<int>&temp,vector<vector<int>>&ans,int index,int n,int count){
        if(index>=num.size()){
            if(n==0 && count==0){
                ans.push_back(temp);
            }
            return;
        }
        if(num[index]<=n){
            temp.push_back(num[index]);
            solve(num,temp,ans,index+1,n-num[index],count-1);
            temp.pop_back();
        }
        solve(num,temp,ans,index+1,n,count);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> num;
        for(int i=0; i<9; i++){
            num.push_back(i+1);
        }
        int index = 0;
        solve(num,temp,ans,index,n,k);
        return ans;
    }
};
