class Solution {
public:
    vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int r, int c, int n,vector<vector<int>>& grid,vector<vector<int>>& color,
                vector<vector<bool>>& visited, int& change){
        
        visited[r][c] = true;
        if(color[r][c] == -1){
            color[r][c] = change;
        }
        
        

        

        for(int i=0; i<4; i++){
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, n, grid, color, visited,change);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<int>>color(n, vector<int>(n, -1));

        vector<vector<bool>>visited(n, vector<bool>(n, false));
        int change = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(i,j,n,grid,color,visited,change);
                    change = 2;
                    
                }
            }
        }

        queue<pair<int,int>>q;
        
        vector<vector<int>>dist(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(color[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }
        

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            

            for(int i=0; i<4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1 && color[nr][nc] == 2){
                    return dist[r][c];
                }
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc] == 0){
                    visited[nr][nc] = true;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }

        }

        return -1;


    }
};
