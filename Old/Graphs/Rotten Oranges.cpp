class Solution {
     bool isValid(vector<vector<int>>&grid,vector<vector<int>>&visited, int i, int j, int n,int m){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1 && visited[i][j]!=2){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }
        vector<pair<int,int>>moves = {{1,0},{0,1},{-1,0},{0,-1}};
        int time = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            
            for(auto move : moves){
                int newi = i + move.first;
                int newj = j + move.second;

                if(isValid(grid,visited,newi,newj,n,m)){
                    q.push({{newi,newj},t+1});
                    visited[newi][newj] = 2;
                }
            }

        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};
