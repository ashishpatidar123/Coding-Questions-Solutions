class Solution {

public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startx = 0;
        int starty = 0;
        int keys = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '@'){
                    startx = i;
                    starty = j;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    keys++;
                }
            }
        }
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << keys)));
        visited[startx][starty][0] = true;
        queue<pair<pair<int,int>, int>> q;
        q.push({{startx, starty}, 0});
        int moves = 0;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<pair<int,int>, int> p = q.front();
                q.pop();
                int r = p.first.first;
                int c = p.first.second;
                int state = p.second;
                if(state == (1 << keys) - 1){
                    return moves;
                }
                for(int j=0; j<4; j++){
                    int nr = r + dirs[j][0];
                    int nc = c + dirs[j][1];
                    if(nr >= m || nr < 0 || nc >= n || nc < 0 || grid[nr][nc] == '#'){
                        continue;
                    }
                    if((grid[nr][nc] >= 'A' && grid[nr][nc] <= 'F') && (((state >> (grid[nr][nc] - 'A')) & 1) == 0)){
                        continue;
                    }
                    else{
                        int newState = state;
                        if(grid[nr][nc] >= 'a' && grid[nr][nc] <= 'f'){
                            newState = newState | (1 << (grid[nr][nc] - 'a'));
                        }
                        if(!visited[nr][nc][newState]){
                            visited[nr][nc][newState] = true;
                            q.push({{nr, nc}, newState});
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
