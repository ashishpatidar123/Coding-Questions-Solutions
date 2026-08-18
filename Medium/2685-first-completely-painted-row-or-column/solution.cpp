class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int,pair<int,int>>entries;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                entries[mat[i][j]] = {i,j+n+m};
            }
        }
        unordered_map<int,int>count;
        for(int i=0; i<m*n; i++){
            int entry = arr[i];
            int row = entries[entry].first;
            int col = entries[entry].second;

            count[row]++;
            count[col]++;

            if(count[row]==n){
                return i;
            }
            else if(count[col]==m){
                return i;
            }
        }
        return -1;
    }
};
