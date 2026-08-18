vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int,array<int,3>> m;
    // storing the frequency of the element corresponding to it's array
    for(int i=0; i<A.size(); i++){
        m[A[i]][0]++;
    }
    for(int i=0; i<B.size(); i++){
        m[B[i]][1]++;
    }
    for(int i=0; i<C.size(); i++){
        m[C[i]][2]++;
    }
    
    vector<int> ans;
    for(auto i:m){
        int a  = i.second[0];
        int b = i.second[1];
        int c = i.second[2];
        // checking if the frequency of the element is non zero for atleast 2 arrays
        if((a>=1 && b>=1) || (a>=1 && c>=1) || (b>=1 && c>=1)){
               
            ans.push_back(i.first);         
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}
