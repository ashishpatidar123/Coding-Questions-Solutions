class Solution {
    void dfs(int i, int j, int row, int col, string&word,string &path, vector<vector<char>>&board,
        vector<vector<bool>>&visited,bool &ans){
        // if the size of the path travesed till now is equal to word then check if the path is same as word or not
        // if it is then make ans true and return
        // else simply return
        if(path.size()==word.size()){
            if(path==word){
                ans = true;
            }
            return;
        }
        // if indexes are out of bound then return
        if(i<0 || i>=row || j<0 || j>=col){
            return;
        }
        // if we already found the path then return
        if(ans==true){
            return;
        }
        // if the cell was already visited earlier then return
        if(visited[i][j]==true){
            return;
        }
        // mark visited and add the letter to the path
        visited[i][j]=true;
        path.push_back(board[i][j]);
        dfs(i+1,j,row,col,word,path,board,visited,ans);
        dfs(i,j+1,row,col,word,path,board,visited,ans);
        dfs(i-1,j,row,col,word,path,board,visited,ans);
        dfs(i,j-1,row,col,word,path,board,visited,ans);
        // pop out the last added letter
        path.pop_back();
        // mark the cell unvisited so that we can check further
        visited[i][j]=false;
        return;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        // creating a variable to store the path
        string path = "";
        //  a variable to store the ans
        bool ans = false;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        // traverse the grid
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                dfs(i,j,row,col,word,path,board,visited,ans);
                // if ans is true which means we have found the word thus return true
                if(ans){
                    return true;
                }
                // else re initalise path and move to next cell
                path = "";
            }
        }
        return false;
    }
};
