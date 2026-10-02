class Solution {
    
    void dfs(int& count, int& total, int node, vector<int>&visited, vector<vector<int>>&adj
                            , vector<int>&degree){
        visited[node] = true;
        count++;
        total += degree[node];
        for(auto v: adj[node]){
            if(!visited[v]){
                dfs(count, total, v, visited, adj, degree);
            }
        }

    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        int ans = 0;
        vector<vector<int>>adj(n);
        vector<int>degree(n);

        for(int i=0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
            degree[x]++;
            degree[y]++;
        }
        vector<int>visited(n,0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                int count = 0;
                int total = 0;
                dfs(count, total, i, visited, adj, degree);
                int edge = total/2;
                if(edge == (count*(count-1))/2){
                    ans++;
                }
            } 
        }

        return ans;

        
    }
};