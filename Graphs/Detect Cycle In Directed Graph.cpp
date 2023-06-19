#include<bits/stdc++.h>
bool dfs(int node,unordered_map<int,list<int>>&adj,
        unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsCalled){
        // mark both visited and dfscalled true
        visited[node]=true;
        dfsCalled[node]=true;
        
        // traverse all the connected nodes
        for(auto i:adj[node]){
          // if the node is not visited earlier then call the dfs for it
            if(visited[i]!=true){
                bool ans = dfs(i,adj,visited,dfsCalled);
                if(ans==true){
                  return true;
                }
            }
            // else if the node is visited and dfs is also called then return 
            // true which means a cycle is detected
            else if(visited[i]==true && dfsCalled[i]==true){
                return true;
            }
        }
        // mark dfscalled false
        // because we returned back from the call
        dfsCalled[node] = false;
        return false;
    }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    // create a adjacency list
    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);

    }
    // create a map to track whether the node is visited or not
    unordered_map<int,bool> visited;
    // create a map to track whether the dfs call is made or not for the node
    unordered_map<int,bool> dfsCalled;
    for(int i=1; i<=n; i++){
      
        if(visited[i]!=true){
            bool ans = dfs(i,adj,visited,dfsCalled);
            if(ans==true){
                return 1;
            }
        }
        
    }
    return 0;
}
