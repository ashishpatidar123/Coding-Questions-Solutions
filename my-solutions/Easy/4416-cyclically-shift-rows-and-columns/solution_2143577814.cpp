class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        vector<vector<int>>ans = grid;

        for(int i=0; i<n; i++){
            int k = rowShift[i];

            for(int j=0; j<n; j++){
                ans[i][(j-k+n)%n] = grid[i][j];
            }
        }
        vector<vector<int>>ans2 = ans;
        for(int j=0; j<n; j++){
            int k = colShift[j];

            for(int i=0; i<n; i++){
                ans2[(i-k+n)%n][j] = ans[i][j];
            }
        }

        return ans2;
        
    }
};