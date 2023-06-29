class Solution {
private:
    void dfs(int node, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;

        for(auto nbr:adj[node]){
            if(visited[nbr]==false){
                dfs(nbr,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int count = 0;

        for(int i=0; i<n; i++){
            if(visited[i]==false){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;

    }
};
