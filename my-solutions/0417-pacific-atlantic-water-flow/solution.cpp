class Solution {
    void dfs1(int i, int j,int row, int col, vector<vector<bool>>&visited, int prev,vector<vector<int>>& heights){
        if(i<0 || i>=row || j<0 || j>=col){
            return;
        }
        if(heights[i][j]<prev){
            return;
        }
        if(visited[i][j]==true){
            return;
        }
        visited[i][j]=true;
        prev = heights[i][j];
        dfs1(i+1,j,row,col,visited,prev,heights);
        dfs1(i,j+1,row,col,visited,prev,heights);
        dfs1(i-1,j,row,col,visited,prev,heights);
        dfs1(i,j-1,row,col,visited,prev,heights);
        return;
    }
    // void dfs2(int i, int j,int row, int col, vector<vector<bool>>&visited, int prev,vector<vector<int>>& heights){
    //     if(i<0 || i>=row || j<0 || j>=col){
    //         return;
    //     }
    //     if(heights[i][j]<prev){
    //         return;
    //     }
    //     if(visited[i][j]==true){
    //         return;
    //     }
    //     visited[i][j]=true;
    //     prev = heights[i][j];
    //     dfs2(i+1,j,row,col,visited,prev,heights);
    //     dfs2(i,j+1,row,col,visited,prev,heights);
    //     dfs2(i-1,j,row,col,visited,prev,heights);
    //     dfs2(i,j-1,row,col,visited,prev,heights);
    //     return;
    // }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        if(row==0){
            return {{}};
        }
        int col = heights[0].size();
        if(col==0){
            return {{}};
        }
        vector<vector<bool>>pacific(row,vector<bool>(col,false));
        vector<vector<bool>>atlantic(row,vector<bool>(col,false));

        for(int i=0; i<col; i++){
           dfs1(0,i,row, col,pacific,heights[0][i],heights);
           dfs1(row-1,i,row,col,atlantic,heights[row-1][i],heights);
        }
        for(int i=0; i<row; i++){
           dfs1(i,0,row, col,pacific,heights[i][0],heights);
           dfs1(i,col-1,row,col,atlantic,heights[i][col-1],heights);
        }
        vector<vector<int>>ans;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacific[i][j]==true && atlantic[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
