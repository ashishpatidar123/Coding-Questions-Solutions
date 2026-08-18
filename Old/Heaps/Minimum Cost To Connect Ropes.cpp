int Solution::solve(vector<int> &A) {
    // create a min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<A.size(); i++){
        pq.push(A[i]);
    }
    // now traverse the min heap and take out two minimum element 
    // find their sum and add this to our answer
    // push this to the heap
    // continue this until the size of the queue is less than 1
    int ans = 0;
    while(pq.size()>1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int sum = first+second;
        ans = ans + sum;
        pq.push(sum);
    }
    return ans;
    
}
