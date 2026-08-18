//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        //
        // simple kahns algorithm
        // if topological sort does not contain all the nodes then there exist
        // a cycle in the graph
        
        vector<int>indegree(V);
       
        for(int i=0; i<V; i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto v:adj[u]){
                
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                }
                
            }
            
        }
        
        return V!=ans.size();
       
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
