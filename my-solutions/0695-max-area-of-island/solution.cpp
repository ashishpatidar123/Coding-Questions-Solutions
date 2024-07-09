class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<bool>>&visited,vector<vector<int>>& grid, int &count){
        visited[i][j]=true;
        count++;
        if(j+1<n){
            if(visited[i][j+1]==false && grid[i][j+1]==1){
                dfs(i,j+1,visited,grid,count);
            }
        }
        if(j-1>=0){
            if(visited[i][j-1]==false && grid[i][j-1]==1){
                dfs(i,j-1,visited,grid,count);
            }
        }
        if(i-1>=0){
            if(visited[i-1][j]==false && grid[i-1][j]==1){
                dfs(i-1,j,visited,grid,count);
            }
        }
        if(i+1<m){
            if(visited[i+1][j]==false && grid[i+1][j]==1){
                dfs(i+1,j,visited,grid,count);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int maxi = 0;
    
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    int count = 0;
                    dfs(i,j,visited,grid,count);
                    maxi = max(count,maxi);
                }
            }
        }
        return maxi;
    }
};
