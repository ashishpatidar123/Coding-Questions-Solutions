class Solution {
private: 
    void dfs(int node,int parent,vector<bool>&visited,vector<int>&disc,vector<int>&low,
        unordered_map<int,vector<int>>&adj,vector<vector<int>>&bridges,int timer){
            // mark visited
            // make discovery time =  timer
            // and lowest discovery time = timer
            // increase the timer
            visited[node]=true;
            disc[node]=timer;
            low[node]=timer;
            timer++;
            // traverse all the adjacent nodes
            for(auto nbr:adj[node]){
                // if nbr is equal to parent then move to next nbr
                if(nbr == parent){
                    continue;
                }
                // if nbr is not visited then call dfs for it
                if(visited[nbr]==false){
                    dfs(nbr,node,visited,disc,low,adj,bridges,timer);
                    // after the dfs call returns 
                    // update the lowest discovery time of the node 
                    // by finding the lowest dicovery time among it's neighbours
                    low[node] = min(low[nbr],low[node]);
                    // if the lowest discovery time of the neighbour is greater
                    // than the discovery time of the parent then it means
                    // the nbr has no connections other than the parent
                    // hence it's a bridge
                    if(low[nbr]>disc[node]){
                        bridges.push_back({nbr,node});
                    }

                }
                // if the nbr is visited then update the lowest discovery time of the node
                // by finding the lowest discovery time among it's neighbours
                else{
                    low[node] = min(low[nbr],low[node]);
                }
            }
        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>adj;

        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // maintain the discovery time and the lowest discovery time
        vector<int>disc(n);
        vector<int>low(n);
        vector<bool>visited(n);

        int timer = 0;
        vector<vector<int>> bridges;
        dfs(0,-1,visited,disc,low,adj,bridges,timer);
        return bridges;
    }
};
