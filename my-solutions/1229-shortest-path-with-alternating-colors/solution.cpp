class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        queue<pair<int,pair<int, int>>>q;
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[0][0] = 0; // i=0 j=0 is red
        dist[0][1] = 0; //  i=0 j=1 is blue

        q.push({0,{0, 0}});
        q.push({0,{1, 0}});

        // 0 means red, 1 means blue

        while(!q.empty()){
            auto [node, t] = q.front();
            q.pop();
            int color = t.first;
            int d = t.second;
            if(color == 0){
                int l = blueEdges.size();
                for(int i=0; i<l; i++){
                    int u = blueEdges[i][0];
                    int v = blueEdges[i][1];
                    if(u == node){
                        if(d != INT_MAX && dist[v][1] > d + 1){
                            dist[v][1] = d + 1;
                            q.push({v, {1, dist[v][1]}});
                        }
                    }
                }
            }
            if(color == 1){
                int l = redEdges.size();
                for(int i=0; i<l; i++){
                    int u = redEdges[i][0];
                    int v = redEdges[i][1];
                    if(u == node){
                        if(d != INT_MAX && dist[v][0] > d + 1){
                            dist[v][0] = d + 1;
                            q.push({v, {0, dist[v][0]}});
                        }
                    }
                }
            }
        }
        
        vector<int>answer(n, -1);

        for(int i=0; i<n; i++){
            if(dist[i][0] != INT_MAX){
                answer[i] = (min(dist[i][0], dist[i][1]));
            }
            else if(dist[i][1] != INT_MAX){
                answer[i] = (min(dist[i][0], dist[i][1]));
            }
            else{
                answer[i] = -1;
            }
        }

        return answer;

    }
};
