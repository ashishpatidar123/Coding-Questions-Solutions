class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix[0].size()-1;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            
            int mid = start + (end-start)/2;
            
            
            while(start<=end){
                int element = matrix[i][mid];
                if(element==target){
                    return true;
                }
                else if(element>target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
                mid = start + (end-start)/2;
            }
            start = 0;
            end = col-1;

        }
        return false;

    }
};
