class Solution {
private:
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&visited, int i, int j, int n, int m){
        if(i>=n || i<0 || j>=m || j<0){
            return;
        }
        if(grid[i][j]=='0' || visited[i][j]==true){
            return;
        }
        visited[i][j]=true;

        dfs(grid,visited,i+1,j,n,m);
        dfs(grid,visited,i,j+1,n,m);
        dfs(grid,visited,i-1,j,n,m);
        dfs(grid,visited,i,j-1,n,m);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int count= 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==false && grid[i][j]=='1'){
                    count++;
                    dfs(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};
