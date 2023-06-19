#include <bits/stdc++.h> 
void bfs(unordered_map<int,set<int>>&adj, vector<int> &ans,
            unordered_map<int,bool>&visited, int node){
    
    // create a queue;
    queue<int> q;
    // push the node
    q.push(node);
    // create a variable to store the front node
    int front = 0;
    // mark it as true since we have visited it
    visited[node] = true;
    // run the loop until the queue is empty
    while(!q.empty()){
        // take out the front node
        front = q.front();
        q.pop();
        // push this into our answer array
        ans.push_back(front);
        
        // traverse for all the connected nodes for the front node using
        // the adjacency list
        for(auto i: adj[front]){
            // is the node is not visited then push it into the queue
            // and mark it visited
            if(visited[i]==false){
                q.push(i);
                visited[i] = true;
            }
        }

    }

}
void createAdjlist(unordered_map<int,set<int>>&adj,vector<pair<int, int>> edges){
    
    // create the adjacency list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{   
    // create a adjacency list 
    // here we used set so that our nodes get stored in sorted manner
    unordered_map<int,set<int>> adj;
    // create an answer array
    vector<int> ans;
    // create a map to track whether the node is visited or not
    unordered_map<int,bool> visited;
    
    // generate the adjacency list
    createAdjlist(adj,edges);
    
    // run the loop for all the vertices
    for(int i=0; i<vertex; i++){
        // if the vertex is not visited then call the bfs function for it
        if(visited[i]==false){
            bfs(adj,ans,visited,i);
        }
    }

    return ans;

}
