class Solution {
private:
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
        visited[node]=true;
        for(auto nbr:adj[node]){
            if(visited[nbr]!=true){
                dfs(nbr,visited,adj);
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n);
        
        dfs(source,visited,adj);
        
        if(visited[destination]==false){
            return false;
        }
        return true;
        }
};
