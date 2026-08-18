#include<bits/stdc++.h>
bool compare(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}
void makeSet(vector<int>&parent,vector<int>&rank,int n){
    
    for(int i=0; i<n; i++){
      parent[i]=i;
      rank[i]=0;
    }
}
int findParent(int node,vector<int>&parent){
    if(node == parent[node]){
      return node;
    }
    return parent[node] = findParent(parent[node],parent);
}
void Unionset(int u, int v, vector<int>&parent,vector<int>&rank){
    
    u = findParent(u,parent);
    v = findParent(v,parent);

    if(rank[u]<rank[v]){
      parent[u] = v;
    }
    else if(rank[u]>rank[v]){
      parent[v] = u;
    }
    else{
      parent[u] = v;
      rank[v]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{   
    sort(edges.begin(),edges.end(),compare);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int minWeight = 0;

    for(int i=0; i<edges.size(); i++){
      int u = findParent(edges[i][0],parent);
      int v = findParent(edges[i][1],parent);
      int weight = edges[i][2];

      if(u!=v){
        Unionset(u,v,parent,rank);
        minWeight += weight;
      }
    }
    return minWeight;
}
