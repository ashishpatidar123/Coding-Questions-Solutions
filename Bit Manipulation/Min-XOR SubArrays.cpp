
int Solution::solve(vector<int> &A) {
    int ans = 0;
    // observe that if the size of the array is even then all elements will occur even times
    // in all the subarray so their xor will be zero
    if(A.size()%2==0){
        return ans;
    }
    // elements at odd index will also occur even number of times in all subarrays 
    // so there xor will also be 0
    // Now we're left with even index elements
    for(int i=0; i<A.size(); i= i+2){
        ans = ans^A[i];
    }
    return ans;
    
}
