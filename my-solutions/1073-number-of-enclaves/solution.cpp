class Solution {
public:
    vector<pair<int,int>>moves = {{1,0},{0,1},{-1,0},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        queue<pair<int,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            
            pair<int,int>temp = q.front();
            q.pop();
            
            int x = temp.first;
            int y = temp.second;

            for(int k=0; k<4; k++){
                int i = x + moves[k].first;
                int j = y + moves[k].second;

                if(i<n && i>=0 && j<m && j>=0 && grid[i][j]==1 && visited[i][j]==false){
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
                        
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    count++;
                }
            }
        }
        return count;
    }
};
