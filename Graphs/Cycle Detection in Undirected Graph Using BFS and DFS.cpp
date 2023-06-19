#include<bits/stdc++.h>
bool isCyclicBFS(unordered_map<int,list<int>>&adj,unordered_map<int,int>&parent,
        unordered_map<int,bool>&visited,int node){
        // mark the parent of the source node as -1
        parent[node] = -1;
        // mark it visited
        visited[node] = true;
        // perform the bfs traversal
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int front = q.front();
            q.pop();
            // traverse all the connected nodes
            for(auto i:adj[front]){
                // if the node is visited and is not the parent of the front
                // then it means a cycle is present 
                if(visited[i]==true && i!=parent[front]){
                    return true;
                }
                // else check for the non visited node and push into the queue
                else if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                    parent[i]=front;
                }
            }
        }
        return false;
    }
bool isCyclicDFS(int node,int parent,unordered_map<int,list<int>>&adj,
                unordered_map<int,bool>&visited){

        visited[node] = true;

        for(auto i:adj[node]){

            if(visited[i]==false){
                bool ans = isCyclicDFS(i,node,adj,visited);
                if(ans==true){
                    return true;
                } 
            }
            else if(parent!=i){
                return true;
            }
        }
        return false;     
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{    
    // create a adjacency list
    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    // create a map to track whether the node is visited or not
    unordered_map<int,bool> visited;
    // create a map to store the parent
    unordered_map<int,int> parent;
    
    // run the loop for all the vertices
    for(int i=1; i<=n; i++){
        // if it is not visited then call the helper function
        if(visited[i]==false){
            bool ans = isCyclicBFS(adj,parent,visited,i);
            //bool ans = isCyclicDFS(i,-1,adj,visited);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";

}
