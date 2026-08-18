int Solution::solve(vector<int> &A, int B) {
    // int i = 0;
    // int j = 0;
    
    // int sum = 0;
    // int count = 0;
    
    // for(int i=0; i<A.size(); i++){
    //     sum = 0;
    //     for(int j=i; j<A.size(); j++){
    //         if(sum+A[j]<B){
    //             count++;
    //             sum = sum + A[j];
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // return count;
    // efficient approach
    int n = A.size(); 
    int j = 0;
    int count = 0;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += A[i];
        while(sum>= B){
            sum -= A[j];
            j++;
        }
        count += i-j+1;
    }
    return count;
    
}
