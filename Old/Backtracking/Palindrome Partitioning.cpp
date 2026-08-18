bool isPalindrome(string s,int start,int end){
    
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
void solve(string A,int index,vector<string> &path,vector<vector<string>>&ans){
    if(index>=A.size()){
        ans.push_back(path);
        return;
    }
    
    for(int i=index; i<A.size(); i++){
        
        if(isPalindrome(A,index,i)){
            path.push_back(A.substr(index,i-index+1));
            solve(A,i+1,path,ans);
            path.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>>ans;
    vector<string> path;
    int index = 0;
    solve(A,index,path,ans);
    return ans;
}
