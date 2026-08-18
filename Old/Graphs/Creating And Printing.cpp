#include <bits/stdc++.h> 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    
    // create a 2d array to store the edges
    vector<int> ans[n];
    // store the edges in the ans array
    for(int i=0; i<m; i++){

        int u = edges[i][0];
        int v = edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);

    }
    // create an adjacency list of size equal to number of nodes
    vector<vector<int>> adj(n);
    // traverse for each node
    for(int i=0; i<n; i++){
        // for each node first add the node
        adj[i].push_back(i);
        // now add all other connected nodes
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    // return the adjacency list
    return adj;
}
