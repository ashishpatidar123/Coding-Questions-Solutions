vector<int> Solution::solve(vector<vector<int> > &A) {
    int k = A.size();
    int n = A[0].size();
    vector<int> ans(n*k);
    priority_queue<int>pq;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            pq.push(A[i][j]);
        }
    } 
    int i = n*k-1;
    while(!pq.empty()){
        ans[i--] = pq.top();
        pq.pop();
    }
    return ans;
}
