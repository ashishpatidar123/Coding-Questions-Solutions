class Solution {
public:
    int n;
    vector<vector<int>>graph;
    vector<vector<int>>critical;
    vector<bool>visited;
    vector<int>tin, low;
    vector<int>parent;
    int timer;

    void dfs(int node, int p = -1){
        visited[node] = true;
        tin[node] = low[node] = timer++;

        bool parent_skipped = false;

        for(int v : graph[node]){
            if(v == p && !parent_skipped){
                parent_skipped = true;
                continue;
            }
            if(visited[v]){
                low[node] = min(low[node], tin[v]);
            }
            else{
                dfs(v, node);
                low[node] = min(low[node], low[v]);

                if(low[v] > tin[node]){
                    critical.push_back({node, v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        int l = connections.size();

        graph.resize(n);

        for(int i=0; i<l; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        timer = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        return critical;

    }
};
