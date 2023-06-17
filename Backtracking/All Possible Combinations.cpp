void solve(vector<string> &A,string temp, vector<string>&ans,int index){
    if(index>=A.size()){
        ans.push_back(temp);
        return;
    }
    string hold = A[index];
    for(int i=0; i<hold.size(); i++){
        temp.push_back(hold[i]);
        solve(A,temp,ans,index+1);
        temp.pop_back();
    }
}
vector<string> Solution::specialStrings(vector<string> &A) {
    vector<string> ans;
    string temp = "";
    int index = 0;
    solve(A,temp,ans,index);
    sort(ans.begin(),ans.end());
    return ans;
}
