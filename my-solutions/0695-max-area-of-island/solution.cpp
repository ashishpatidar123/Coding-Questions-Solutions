class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int,int>>q;

        int max_count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int count = 0;
                    count++;

                    q.push({i,j});
                    grid[i][j]=0;

                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();

                        for(int d=0; d<4; d++){
                            int nr = r+dirs[d][0];
                            int nc = c+dirs[d][1];

                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                                count++;
                            }
                        }
                    }

                    max_count = max(count, max_count);
                }
            }
        }

        return max_count;
        
    }
};
