//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    // function to find the topological sort
    void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,vector<pair<int,int>>>&adj,
                stack<int> &st){
            
            visited[node]=true;
            
            for(auto i:adj[node]){
                if(visited[i.first]!=true){
                    dfs(i.first,visited,adj,st);
                }
            }
            st.push(node);
        }
    // function to find the shortest distance   
    void find(stack<int>&st,vector<int>&distance,unordered_map<int,vector<pair<int,int>>>&adj){
        
        // run until the stack is  not empty
        while(!st.empty()){
            
            // find the top element
            int top = st.top();
            st.pop();
            // if it's distance is not infinite then
            if(distance[top]!=INT_MAX){
                // find it's neighbours
                for(auto i:adj[top]){
                    
                    // and update their distance if their current distance is more
                    // than the new distance otherwise don't to anything
                    int temp = distance[top]+i.second;
                    
                    if(temp<distance[i.first]){
                        distance[i.first]=temp;
                    }
                }
            }
            
        }
    }
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        unordered_map<int,vector<pair<int,int>>> adj;
        // create adjacency list 
        // use pair since we alse have weights associated with the edges
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            pair<int,int> p = make_pair(v,weight);
            
            adj[u].push_back(p);
        }
        // create a visited map and stack to perform topological sort
        unordered_map<int,bool> visited;
        stack<int> st;
        
        for(int i=0; i<N; i++){
            if(visited[i]!=true){
                dfs(i,visited,adj,st);
            }
        }
        // after performing topological sort
        // create a distance array
        // initially setting distance as some maximum number for all the nodes except the
        // source node
        // for the source node set distance as 0
        vector<int> distance(N);
        for(int i=0; i<N; i++){
            if(i==0){
                distance[i] = 0;
            }
            else{
                distance[i] = INT_MAX;
            }
        }
        // call the helper function which helps us in finding the shortest distance
        find(st,distance,adj);
        
        // after finding distance if distance of any node is still INT_MAX 
        // then set it to -1 because it means this node is not reachable
        // i.e. it's indegree is 0
        for(int i=0; i<N; i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        // return the distance array
        return distance;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
