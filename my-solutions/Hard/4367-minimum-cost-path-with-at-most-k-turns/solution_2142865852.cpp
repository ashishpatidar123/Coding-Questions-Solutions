class Solution {
public:
    struct State {
        int cost;
        int r;
        int c;
        int dir;
        int turns;
        
        bool operator>(const State& other) const{
            return cost > other.cost;
        }
    };
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 1 && n == 1){
            return grid[0][0];
        }

        int dist[75][75][4][76];

        for(int i=0; i<75; i++){
            for(int j=0; j<75; j++){
                for(int d=0; d<4; d++){
                    for(int t=0; t<75; t++){
                        dist[i][j][d][t] = INT_MAX;
                    }
                }
            }
        }

        priority_queue<State, vector<State>, greater<State>> pq;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        if(n > 1){
            pq.push({grid[0][0] + grid[0][1], 0, 1, 1, 0});
            dist[0][1][1][0] = grid[0][0] + grid[0][1];
        }

        if(m > 1){
            pq.push({grid[0][0] + grid[1][0], 1, 0, 2, 0});
            dist[1][0][2][0] = grid[0][0] + grid[1][0];
        }

        while(!pq.empty()){
            State curr = pq.top();
            pq.pop();

            if(curr.r == m-1 && curr.c == n-1){
                return curr.cost;
            }

            if(curr.cost > dist[curr.r][curr.c][curr.dir][curr.turns]){
                continue;
            }

            for(int d=0; d<4; d++){
                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];

                if(nr >=0 && nr < m && nc >= 0 && nc < n){
                    int nturns = curr.turns + (d != curr.dir ? 1 : 0);

                    if(nturns <= k){
                        int ncost = curr.cost + grid[nr][nc];

                        if(ncost < dist[nr][nc][d][nturns]){
                            dist[nr][nc][d][nturns] = ncost;

                            pq.push({ncost, nr, nc, d, nturns});
                        }
                    }
                }
            }
        }
        return -1;

    }
};