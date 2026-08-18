class Solution {
private:
    void dfs(int node,vector<vector<pair<int, int>>>& graph, vector<bool>&visited, int& count){
        
        visited[node] = true;

        for(auto nbr : graph[node]){
            int v = nbr.first;
            int cost = nbr.second;

            if(!visited[v]){
                count += cost;
                dfs(v, graph, visited, count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
        vector<vector<pair<int, int>>>graph(n);

        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back({v,1});
            graph[v].push_back({u,0});
        }
        int count = 0;
        vector<bool>visited(n, false);

        dfs(0,graph, visited, count);

        return count;



    }
};
