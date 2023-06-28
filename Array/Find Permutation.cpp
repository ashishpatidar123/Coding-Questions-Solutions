vector<int> Solution::findPerm(const string s, int n) {
    int smaller = 1;
    int greater = n;
    vector<int>ans;
    
    for(int i=0; i<n-1; i++){
        if(s[i]=='I'){
            ans.push_back(smaller++);
        }
        else{
            ans.push_back(greater--);
        }
    }
    ans.push_back(smaller);
    return ans;
}
