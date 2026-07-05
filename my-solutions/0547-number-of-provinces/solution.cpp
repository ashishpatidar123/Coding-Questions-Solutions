class Solution {
public:
    void dfs(int node, vector<bool>&visited, vector<vector<int>>& graph){
        visited[node] = true;

        for(auto v : graph[node]){
            if(!visited[v]){
                dfs(v, visited, graph);
            }
        }

        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        vector<vector<int>>graph(n);
        vector<bool>visited(n, false);
        int count = 0;


        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int u = i;
                int v = j;

                if(isConnected[i][j] == 1){
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }

        for(int u=0; u<n; u++){
            if(!visited[u]){
                dfs(u, visited, graph);
                count++;
            }
        }

        return count;
        
    }
};
