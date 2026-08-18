#include <bits/stdc++.h> 
void ts(int node,vector<bool>&visited,stack<int> &st,
                unordered_map<int,list<int>>&adj){
        
        visited[node]=true;

        for(auto i:adj[node]){
            if(visited[i]!=true){
                ts(i,visited,st,adj);
            }
        }
        // after the all function calls are over push the node into the stack
        st.push(node);
    }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool>visited(v);
    // create a stack to store the nodes
    stack<int> st;

    for(int i=0; i<v; i++){
        if(visited[i]!=true){
            ts(i,visited,st,adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
