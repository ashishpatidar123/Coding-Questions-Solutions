class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>>visited(n, vector<bool>(1 << n));
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++){
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int dist = 0;
        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto [node, bitmask] = q.front();
                q.pop();

                if(bitmask == ((1 << n) - 1)){
                    return dist;
                }
                for(auto v : graph[node]){
                    int newBitmask = bitmask | (1 << v);
                    if(!visited[v][newBitmask]){
                        q.push({v, newBitmask});
                        visited[v][newBitmask] = true;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};

