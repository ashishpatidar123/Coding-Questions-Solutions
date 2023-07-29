#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs1(int node, int p,int &timer,unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<int>&tin,vector<int>&low,vector<pair<int,int>>&bridges){
    
	visited[node]=true;
	tin[node] = timer;
	low[node] = timer;
	timer++;

	for(auto v:adj[node]){
		if(v==p){
			continue;
		}
		if(visited[v]==true){
			low[node] = min(low[node],tin[v]);
		}
		else{
			dfs1(v,node,timer,adj,visited,tin,low,bridges);
			low[node] = min(low[node],low[v]);

			if(low[v]>tin[node]){
				bridges.push_back({node,v});
			}
		}
	}
}
void dfs2(int node, int p, int &timer, unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<int>&tin, vector<int>&low,set<int>&points){
     
	visited[node]=true;
	low[node]= timer;
	tin[node]=timer;
	timer++;
    int children = 0;
	for(auto v:adj[node]){
		if(v==p){
			continue;
		}
		if(visited[v]==true){
			low[node] = min(low[node],tin[v]);
		}
		else{
            dfs2(v,node,timer,adj,visited,tin,low,points);
			low[node] = min(low[node],low[v]);
			if(low[v]>=tin[node] && p!=-1){
				points.insert(node);
			}
			++children;
		}
	}
	if(p==-1 && children>1){
		points.insert(node);
	}
}
int main() {
	int n;
	int m;
	cin>>n>>m;

	unordered_map<int,vector<int>>adj;

	for(int i=0; i<m; i++){
		int u;
		int v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool>visited(n,false);
	vector<int>tin(n,-1);
	vector<int>low(n,-1);

    vector<pair<int,int>>bridges;
    int timer = 0;
	for(int i=0; i<n; i++){
		if(visited[i]!=true){
            dfs1(i,-1,timer,adj,visited,tin,low,bridges);
		}
	}

	for(int i=0; i<n; i++){
		visited[i]=false;
		tin[i] = -1;
		low[i] = -1;
	}
	timer = 0;
	set<int>points;

	for(int i=0; i<n; i++){
		if(visited[i]==false){
			dfs2(i,-1,timer,adj,visited,tin,low,points);
		}
	}

	cout<<points.size()<<endl;
	for(auto p:points){
		cout<<p<<" ";
	}
	cout<<endl;
	cout<<bridges.size()<<endl;
    sort(bridges.begin(),bridges.end());
	for(int i=0; i<bridges.size(); i++){
		int u = bridges[i].first;
		int v = bridges[i].second;

		if(u<v){
			cout<<u<<" "<<v<<endl;
		}
		else{
			cout<<v<<" "<<u<<endl;
		}
	}
	return 0;
}
