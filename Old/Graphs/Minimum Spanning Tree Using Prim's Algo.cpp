//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    private:
    
    int findMin(vector<int>&key,vector<bool>&MST){
        // finding the minimum vertex from Non-MST vertices
        int min = INT_MAX;
        int index;
        for(int i=0; i<key.size(); i++){
            
            if(MST[i]==false && key[i]<min)
            {
                min = key[i];
                index = i;
            }
        }
        return index;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        // a MST array
        vector<bool> MST(V);
        // a key array
        vector<int> key(V);
        // intialising
        for(int i=0; i<V; i++){
            MST[i]=false;
            key[i]=INT_MAX;
        }
        // make the key of the starting node as 0;
        key[0]=0;
        
        vector<int>parent(V);
        // make parent of starting node as -1
        parent[0]=-1;
        // traverse for all nodes
        for(int i=0; i<V; i++){
            
            // find the minimum node
            int u = findMin(key,MST);
            // marks it's MST as true
            MST[u] = true;
            // traverse for it's connecting edges
            for(auto i:adj[u]){
                
                int v = i[0];
                int weight = i[1];
                // if the node is not included and it's weight is less than it's key then
                // update it's key and parent
                if(MST[v]==false && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                    
                }
            }
        }
        // find the sum
        int sum = 0;
        
        for(int i=0; i<V; i++){
            sum+=key[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
