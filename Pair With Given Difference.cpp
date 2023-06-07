int Solution::solve(vector<int> &A, int B) {
    
    map<int,int> m;
    
    //store all elements in a map
    for(int i =0; i<A.size(); i++){
        
        // if B==0 and there exists two equal numbers then return 1
        if(m.find(A[i])!=m.end() && B==0){
            return 1;
        }
        // insert number with value 1 in map
        m.insert({A[i],1});
        
    }
    
    // traverse the vector and find A[i] + B in map
    for(int i=0; i<A.size(); i++){
        
        // if we find A[i]+B in map and B!=0 then return 1
        if(m.find(A[i]+B)!=m.end() && B!=0){
            return 1;
        }
    }
    // else return 0
    return 0;
    
}
