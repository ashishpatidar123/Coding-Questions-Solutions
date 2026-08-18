//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Union find by rank
// {   private:
       // find parent 
//     int find(int node, vector<int>&parent){
//         if(parent[node]==node){
//             return node;
//         }
//         return parent[node] = find(parent[node],parent);
//     }
    // perform union on the basis of rank
//     void Union(int u, int v, vector<int>&parent,vector<int>&rank){
//         // u = find(u,parent);
//         // v = find(v,parent);
           // if parents are same then return
//         // if(u==v){
//         //     return;
//         // }
          // if rank of one is greater than the other then make higher rank node as 
          // parent of the lower rank node
//         // if(rank[u]<rank[v]){
//         //     parent[u]=v;
//         // }
//         // else if(rank[u]>rank[v]){
//         //     parent[v]=u;
//         // }
          // if ranks are same then make anyone as parent of the other and increase the rank of
          // the parent by 1
//         // else{
//         //     parent[v]=u;
//         //     rank[u]++;
//         // }
//     }
//     public:
//     //Function to detect cycle using DSU in an undirected graph.
// 	int detectCycle(int V, vector<int>adj[])
// 	{
	   
// 	    vector<int> parent(V);
// 	    vector<int> rank(V);
        
        // initialise parent of each node as 
// 	    for(int i=0; i<V; i++){
// 	        parent[i]=i;
// 	        rank[i]=0;
// 	    }
	    
	    
// 	    for(int i=0; i<V; i++){
	       
// 	        for(int j=0; j<adj[0].size(); j++){
	            
// 	            int u = find(i,parent);
// 	            int v = find(adj[i][j],parent);
	           
// 	            if(u==v){
// 	                return 1;
// 	            }
// 	            else{
// 	                Union(u,v,parent,rank);
// 	            }
// 	        }
// 	    }
	   
// 	   return 0;
// 	}
// Union find
  vector<int> parent;
    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        return find(parent[x]);
    }
    void unio(int x , int y)
    {
        parent[x] = y;
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V);
	    for(int i = 0; i < V ; i++)
	    {
	        parent[i] = i;
	    }
	    for(int i = 0 ; i < V ; i++)
	    {
	        for(int j = 0 ; j < adj[i].size() ; j++)
	        {
	           if(adj[i][j] < i)
	           {
	               continue;
	           }
	            int xroot = find(i);
	            int yroot = find(adj[i][j]);
	            if(xroot == yroot)
	            {
	                return 1;
	            }
	            else
	            {
	                unio(xroot,yroot);
	            }
	        }
	    }
	    return 0;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
