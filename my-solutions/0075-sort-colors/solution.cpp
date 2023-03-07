class Solution {
public:
    void sortColors(vector<int>& A) {
        int ptr = 0;
    int ptr2 = A.size()-1;
    for(int i=0; i<A.size(); i++){
        if(ptr<ptr2){
            if((A[ptr]==1)&&(A[ptr2]==0)){
                int temp = A[ptr];
                A[ptr] = A[ptr2];
                A[ptr2] = temp;
                ptr++;
                ptr2--;
                
            }
            else if(A[ptr]==1){
                ptr2--;
            }
            else if(A[ptr]==0){
                ptr++;
            }
            else if(A[ptr]==2){
                ptr++;
            }
            
        }
            
    }
    ptr=0;
    ptr2=A.size()-1;
    for(int i=0; i<A.size(); i++){
        if(ptr<ptr2){
            if((A[ptr]==2)&&(A[ptr2]==0)){
                int temp = A[ptr];
                A[ptr] = A[ptr2];
                A[ptr2] = temp;
                ptr++;
                ptr2--;
                
            }
            else if(A[ptr]==2){
                ptr2--;
            }
            else if(A[ptr]==0){
                ptr++;
            }
            else if(A[ptr]==1){
                ptr++;
            }
            
        }
            
    }
    ptr = 0;
    ptr2 = A.size()-1;
    for(int i=0; i<A.size(); i++){
        if(ptr<ptr2){
            if((A[ptr]==2)&&(A[ptr2]==1)){
                int temp = A[ptr];
                A[ptr] = A[ptr2];
                A[ptr2] = temp;
                ptr++;
                ptr2--;
                
            }
            else if(A[ptr]==2){
                ptr2--;
            }
            else if(A[ptr]==1){
                ptr++;
            }
            else if(A[ptr]==0){
                ptr++;
            }
            
        }
            
    }
    for(int i=0; i<A.size(); i++){
            cout<<A[i]<<" ";
        }
    }
};
