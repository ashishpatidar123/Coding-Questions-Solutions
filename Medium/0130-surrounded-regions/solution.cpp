class Solution {
public:

    vector<pair<int,int>>moves = {{1,0},{0,1},{-1,0},{0,-1}};

    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        queue<pair<int,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
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

                if(i<n && i>=0 && j<m && j>=0 && board[i][j]=='O' && visited[i][j]==false){
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
                        
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }

    }
};
