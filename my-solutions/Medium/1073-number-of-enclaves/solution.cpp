class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int total = 0;

        queue<pair<int,int>>q;

        int dirs[] = {0,1,0,-1,0};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    total ++ ;
                    if(i == 0 || j == 0 || i == m-1 || j == n-1){
                        q.push({i,j});
                        grid[i][j] = 0;
                        total--;
                    }
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int l=0; l<4; l++){
                int nr = r + dirs[l];
                int nc = c + dirs[l+1];

                if(nr >=0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    total--;
                    q.push({nr, nc});

                }
            }

        }
        return total;
        
    }
};
