#include<bits/stdc++.h>
int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	// simple Prims algorithm  
	unordered_map<int,vector<pair<int,int>>> adj;

    for(int i=0; i<k; i++){
        int u = pipes[i][0];
        int v = pipes[i][1];
        int w = pipes[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }
	// create a dummy node 
	// from which the pipe connection is created with cost equal to the cost of
	// creating a well in that house
	for(int i=1; i<=n; i++){
		adj[0].push_back(make_pair(i,wells[i-1]));
		adj[i].push_back(make_pair(0,wells[i-1]));
	}
	vector<bool>MST(n+1);
	vector<int>parent(n+1);
	vector<int> key(n+1);

	for(int i=0; i<=n; i++){
		MST[i]=false;
		parent[i]=-1;
		key[i]=INT_MAX;
	}

	parent[0] = -1;
	key[0] = 0;
	for(int i=1; i<=n; i++){
		int min = INT_MAX;
		int u;

		for(int i=0; i<=n; i++){
			if(MST[i]==false && key[i]<min){
				min = key[i];
				u = i;
			}
		}
		MST[u] = true;

		for(auto j:adj[u]){
			int v = j.first;
			int w = j.second;
            
			
			if(MST[v]==false && key[v]>w){
				key[v]=w;
				parent[v]=u;
			}
			
		}
	}
	int sum = 0;
	for(int i=1; i<=n; i++){
		if(key[i]==INT_MAX){
			sum+=wells[i-1];
		}
		else{
			sum+=key[i];
		}
	}
    return sum;
}
