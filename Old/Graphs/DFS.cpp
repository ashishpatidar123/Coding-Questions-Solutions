void dfs(unordered_map<int,set<int>>&adj,vector<int> &component,
                unordered_map<int,bool> &visited,int node){
        // push the given node in the component vector
        component.push_back(node);
        // mark it visited
        visited[node]=true;
        // traverse all the connected nodes and 
        // recursively call for the connected nodes
        for(auto i:adj[node]){
            if(visited[i]==false){
                dfs(adj,component,visited,i);
            }
        }
    }
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   
    // creat a map for creating a adjacency list
    unordered_map<int, set<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
    // create a map to track whether the node is visited or not
    unordered_map<int,bool> visited;

    vector<vector<int>> ans;
    // traverse all the vertices
    for(int i=0; i<V; i++){
        // if the vertices is not visited
        if(visited[i]==false){
            // then call dfs for it
            vector<int> component;
            dfs(adj,component,visited,i);
            ans.push_back(component);
        }
    }
    return ans;
}
