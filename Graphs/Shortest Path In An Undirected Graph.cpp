#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// use bfs to find parents of each node
	// starting from the source node
	vector<bool> visited(n+1,false);

	unordered_map<int,vector<int>> adj;

	for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> parent(n+1);

	queue<int> q;
	q.push(s);
    parent[s]=-1;
	while(!q.empty()){

		int front  = q.front();
		q.pop();

		for(auto i:adj[front]){
			if(visited[i]!=true){
				visited[i]=true;
				parent[i] = front;
				q.push(i);
			}
		}

	}
    //traverse the parents of destination node until we find the source node
	int currentNode = t;
	vector<int> ans;
	ans.push_back(currentNode);
	while(currentNode!=s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
