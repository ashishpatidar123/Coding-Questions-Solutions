void solve(vector<int>&A,int target, int index, vector<int> &temp, set<vector<int>>&store){
    if(index==A.size()){
        if(target==0){
            store.insert(temp);
        }
        return;
    }
    // picking the element
    if(A[index]<=target){
        temp.push_back(A[index]);
        solve(A,target-A[index],index,temp,store);
        temp.pop_back();
    }
    // not picking the element
    solve(A,target,index+1,temp,store);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> temp;
    int index =0;
    sort(A.begin(),A.end());
    set<vector<int>> store;
    solve(A,B,index,temp,store);
    for(auto i:store){
        ans.push_back(i);
    }
    
    return ans;
}
