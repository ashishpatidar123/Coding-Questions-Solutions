void dfs(int node, vector<vector<int> > &B,unordered_map<int,bool> &visited,unordered_map<int,vector<int>>&adj){
    visited[node] = true;
    
    for(auto i:adj[node]){
        if(visited[i]==false){
            dfs(i,B,visited,adj);
        }
    }
    return;
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    // the idea is to find the number of disconnected components
    unordered_map<int,vector<int>> adj;
    
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    unordered_map<int,bool> visited;
    int count = 0;
    for(int i=1; i<=A; i++){
        if(visited[i]==false){
            count++;
            dfs(i,B,visited,adj);
        }
    }
    return count;
}
