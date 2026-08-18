class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int,int>>q;

        vector<vector<int>>dist(m, vector<int>(n, 0));

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = true;                   
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();


            for(int i=0; i<4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if(nr >=0 && nr < m && nc >=0 && nc < n && !visited[nr][nc]){

                    visited[nr][nc] = true;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
 
                    

                }
            }
        }

        return dist;


        
    }
};
