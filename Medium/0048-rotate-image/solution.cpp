class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
    
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
               swap(A[i][j],A[j][i]);
            }
        }
        for(int i=0; i<row; i++){
            int start = 0;
            int end = col-1;
            while(start<=end){
                swap(A[i][start++],A[i][end--]);
            }
        }
    }
};
