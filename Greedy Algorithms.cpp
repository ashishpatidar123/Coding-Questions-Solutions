int Solution::maxp3(vector<int> &A) {
    int max1 = -1;
    int max2 = -1;
    int max3 = -1;
    int min1 = -1;
    int min2 = -1;
    if(A.size()==3){
        return A[0]*A[1]*A[2];
    }
    int cp = INT_MIN;
    for(int i=0; i<A.size(); i++){
        if(A[i]>cp){
            cp = A[i];
            max1 = i;
        }
    }
    cp = INT_MIN;
    for(int i=0; i<A.size(); i++){
        if(A[i]>cp && i!=max1){
            cp = A[i];
            max2 = i;
        }
    }
    cp = INT_MIN;
    for(int i=0; i<A.size(); i++){
        if(A[i]>cp && i!=max1 && i!=max2){
            cp = A[i];
            max3 = i;
        }
    }
    cp = INT_MAX;
    for(int i=0; i<A.size(); i++){
        if(A[i]<cp){
            cp = A[i];
            min1 = i;
        }
    }
    cp = INT_MAX;
    for(int i=0; i<A.size(); i++){
        if(A[i]<cp && i!=min1){
            cp = A[i];
            min2 = i;
        }
    }
    if(min2!=-1 && min1!=-1 && A[min2]<0 && A[min1]<0){
        return max(A[min2]*A[min1]*A[max1],A[max1]*A[max2]*A[max3]);
    }
    return A[max1]*A[max2]*A[max3];
    
}
