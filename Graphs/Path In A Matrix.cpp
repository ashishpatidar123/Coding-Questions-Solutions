int Solution::checkPath(vector<vector<int> > &A) {
    // source coordinates
    int sx = 0;
    int sy = 0;
    // destination coordinates
    int dx = 0;
    int dy = 0;
    int n = A.size();
    int m = A[0].size();
    // creating visited matrix
    vector<vector<int>> visited(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
            if(A[i][j]==1){
                sx = i;
                sy = j;
                visited[i][j]=true;
            }
            if(A[i][j]==2){
                dx = i;
                dy = j;
            }
        }
    }
    // creating a queue
    queue<pair<int,int>> q;
    q.push({sx,sy});
    // possible moves
    pair<int,int> moves[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    int x;
    int y;
    // run the loop until the queue is empty
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        // check for all moves
        for(auto i: moves){
            x = curr.first + i.first;
            y = curr.second + i.second;
            // if we reach the destination
            // return
            if(x==dx && y==dy){
                return 1;
            }
            // check for valid move
            if(x>=0 && x<n && y>=0 && y<m && A[x][y]==3 && visited[x][y]==false){
                q.push({x,y});
                visited[x][y] = true;
            }
        }
    }
    return 0;
}
