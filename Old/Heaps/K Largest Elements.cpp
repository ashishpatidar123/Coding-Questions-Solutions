vector<int> Solution::solve(vector<int> &A, int B) {
    // create a min heap 
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0; i<B; i++){
        pq.push(A[i]);
    }
    for(int i=B; i<A.size(); i++){
        if(A[i]>pq.top()){
            pq.pop();
            pq.push(A[i]);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
