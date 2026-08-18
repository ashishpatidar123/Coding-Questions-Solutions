class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int r, int c,vector<vector<bool>>& reachable, 
                vector<vector<int>>& heights){

        reachable[r][c] = true;

        for(int d=0; d<4; d++){
            int nr = r + dirs[d][0];
            int nc = c + dirs[d][1];

            if(nr >=0 && nr < m && nc >=0 && nc < n){
                if(!reachable[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    dfs(nr, nc, reachable, heights);
                }
            }
                
        }

        return;
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>>pacific(m, vector<bool>(n, false));
        vector<vector<bool>>atlantic(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            dfs(i, 0, pacific, heights);
        }
        for(int j=0; j<n; j++){
            dfs(0, j, pacific, heights);
        }
        for(int i=0; i<m; i++){
            dfs(i, n-1, atlantic, heights);
        }
        for(int j=0; j<n; j++){
            dfs(m-1, j, atlantic, heights);
        }

        vector<vector<int>>result;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
        
    }
};
