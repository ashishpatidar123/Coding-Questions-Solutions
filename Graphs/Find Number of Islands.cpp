class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<int>>&grid,vector<vector<bool>>&visited){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || visited[i][j]==true){
            return;
        }
        
        visited[i][j]=true;
        
        dfs(i+1,j,n,m,grid,visited);
        dfs(i,j+1,n,m,grid,visited);
        dfs(i-1,j,n,m,grid,visited);
        dfs(i,j-1,n,m,grid,visited);
        
        return;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        int k = operators.size();
        //vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<int>ans;
        int count=0;
        for(int i=0; i<k; i++){
            grid[operators[i][0]][operators[i][1]] = 1;
            vector<vector<bool>>visited(n,vector<bool>(m,false));
            count=0;
            for(int j=0; j<n; j++){
                for(int l=0; l<m; l++){
                    if(grid[j][l]==1 && visited[j][l]==false){
                        dfs(j,l,n,m,grid,visited);
                        count++;
                    }
                    
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
