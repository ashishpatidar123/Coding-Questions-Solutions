void dfs(int node, vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    visited[node]=true;
    for(auto i:adj[node]){
        if(visited[i]==false){
            dfs(i,visited,adj);
        }
    }
    return;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int,vector<int>>adj;
    
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(A+1,false);
    int count = 0;
    
    for(int i=1; i<=A; i++){
        if(visited[i]==false){
            count++;
            dfs(i,visited,adj);
        }
    }
    return count;
}
