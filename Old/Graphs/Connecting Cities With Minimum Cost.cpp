#include <bits/stdc++.h> 
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
	unordered_map<int,vector<pair<int,int>>>adj;
	for(int i=0; i<m; i++){
		int u = connections[i][0];
		int v = connections[i][1];
		int weight = connections[i][2];

		adj[u].push_back({v,weight});
		adj[v].push_back({u,weight});
	}
	vector<bool>MST(n+1);
	vector<int>key(n+1);
	vector<int>parent(n+1);
    
	for(int i=1; i<=n; i++){
		parent[i]=-1;
		key[i]=INT_MAX;
		MST[i]=false;
	}
	key[1] = 0;
	parent[1] = -1;
    
	for(int i=1; i<n; i++){
		int min = INT_MAX;
		int u;

		for(int v=1; v<=n; v++){
			if(MST[v]==false && key[v]<min){
				min = key[v];
				u = v;
			}
		}
		MST[u] = true;

		for(j:adj[u]){
            int v = j.first;
			int wt = j.second;

			if(MST[v]==false && key[v]>wt){
				key[v]=wt;
				parent[v]=u;
			}
		}
	}
	int minCost = 0;
	for(int i=1; i<=n; i++){
		if(key[i]==INT_MAX){
			return -1;
		}
		minCost += key[i];
	}
	return minCost;

}
