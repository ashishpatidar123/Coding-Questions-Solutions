class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<int>>dist(n, vector<int>(n, -1));

        vector<vector<int>> dirs = {{1,0},{1,-1},{0,1},{0,-1},{1,1},{-1,-1},{-1,0},{-1,1}};

        queue<pair<int,int>>q;

        if(grid[0][0] == 0){
            q.push({0,0});
            dist[0][0] = 1;
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r == n-1 && c == n-1){
                return dist[n-1][n-1];
            }

            for(int i=0; i<8; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1 && grid[nr][nc] == 0){
                    
                    // cout<<nr<<" "<<nc<<endl;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                    // grid[nr][nc] = 1;

                }
            }
        }

        return -1;
    }
};
