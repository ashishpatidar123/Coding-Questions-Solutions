class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        // vector<vector<int>>ans = grid;

        // for(int i=0; i<n; i++){
        //     int k = rowShift[i];

        //     for(int j=0; j<n; j++){
        //         ans[i][(j-k+n)%n] = grid[i][j];
        //     }
        // }
        // vector<vector<int>>ans2 = ans;
        // for(int j=0; j<n; j++){
        //     int k = colShift[j];

        //     for(int i=0; i<n; i++){
        //         ans2[(i-k+n)%n][j] = ans[i][j];
        //     }
        // }

        // return ans2;

        vector<vector<int>>ans(n, vector<int>(n));

        for(int i=0; i<n; i++){
            int r = rowShift[i]%n;

            for(int j=0; j<n; j++){
                int new_j = (j-r+n)%n;

                int c = colShift[new_j]%n;
                int new_i = (i-c+n)%n;

                ans[new_i][new_j] = grid[i][j];
            }
        }
        return ans;
        
    }
};