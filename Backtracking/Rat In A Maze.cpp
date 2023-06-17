class Solution{
    
    bool isSafe(int x, int y, vector<vector<int>> &m, vector<vector<int>> visited, int n){
        if((x<n && x>=0) && (y<n && y>=0)&& visited[x][y]==0 && m[x][y]==1  ){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<string> &ans, string path, vector<vector<int>> &m, vector<vector<int>> visited,
                   int x, int y, int n){
                       
                    if(x==n-1 && y==n-1){
                        ans.push_back(path);
                        return ;
                    }
                    // marking the location visited as 1
                    visited[x][y] = 1;
                    
                    //down
                    int newx = x+1;
                    int newy = y;
                    if(isSafe(newx,newy,m,visited,n)){
                        path.push_back('D');
                        solve(ans,path,m,visited,newx,newy,n);
                        path.pop_back();
        
                    }
                    //left
                    newx = x;
                    newy = y-1;
                    if(isSafe(newx,newy,m,visited,n)){
                        path.push_back('L');
                        solve(ans,path,m,visited,newx,newy,n);
                        path.pop_back();
        
                    }
                    //right
                    newx = x;
                    newy = y+1;
                    if(isSafe(newx,newy,m,visited,n)){
                        path.push_back('R');
                        solve(ans,path,m,visited,newx,newy,n);
                        path.pop_back();
        
                    }
                    //up
                    newx = x-1;
                    newy = y;
                    if(isSafe(newx,newy,m,visited,n)){
                        path.push_back('U');
                        solve(ans,path,m,visited,newx,newy,n);
                        path.pop_back();
        
                    }
                    
                    visited[x][y] = 0;
                    
                       
       }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string path = "";
        int x_src = 0;
        int y_src = 0;
        
        if(m[0][0]==0){
            return ans;
        }
        
        vector<vector<int>> visited(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        solve(ans,path,m,visited,x_src,y_src,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
