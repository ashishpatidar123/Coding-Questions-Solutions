void solve(vector<int>&num,vector<int>&temp,vector<vector<int>>&ans,int index,int count){
  // if index is greater than or equal to size
    if(index>=num.size()){
      // if we get k numbers then push it into the answer
      // else return
        if(count==0){
            ans.push_back(temp);
        }
        return;
    }
  // push the number
    temp.push_back(num[index]);
  // call for the next index and with count-1 because we had taken one number
    solve(num,temp,ans,index+1,count-1);
  // pop out that number
    temp.pop_back();
  // call for the next index without taking the number
    solve(num,temp,ans,index+1,count);
    
}
vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> num;
    for(int i=0; i<n; i++){
        num.push_back(i+1);
    }
    int index = 0;
    solve(num,temp,ans,index,k);
    return ans;
}
