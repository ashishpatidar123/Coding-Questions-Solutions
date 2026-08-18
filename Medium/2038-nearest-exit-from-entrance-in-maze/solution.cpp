class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>>dist(m, vector<int>(n, -1));
        vector<vector<int>>dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int mini = INT_MAX;
        queue<pair<int, int>>q;
        dist[entrance[0]][entrance[1]] = 0;
        q.push({entrance[0], entrance[1]});

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if((nr >= 0 && nr < m && nc >=0 && nc < n) && (maze[nr][nc] == '.') && (dist[nr][nc] == -1)){

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});

                    if(nr == 0 || nr == m-1 && dist[nr][nc] > 0){
                        mini = min(dist[nr][nc], mini);
                    }
                    if(nc == 0 || nc == n-1 && dist[nr][nc] > 0){
                        mini = min(dist[nr][nc], mini);
                    }

                }
            }
        }

        

        // for(int i=0; i<n; i++){
            
        //     if(dist[0][i] > 0){
        //         mini = min(dist[0][i], mini);
        //     }
        //     if(dist[m-1][i] > 0){
        //         mini = min(dist[m-1][i], mini);
        //     }
        // }
        // for(int i=0; i<m; i++){
           
        //     if(dist[i][0] > 0){
        //         mini = min(dist[i][0], mini);
        //     }
        //     if(dist[i][n-1] > 0){
        //         mini = min(dist[i][n-1], mini);
        //     }
        // }
        if(mini == INT_MAX || mini == 0){
            return -1;
        }
        return mini;


        
    }
};
