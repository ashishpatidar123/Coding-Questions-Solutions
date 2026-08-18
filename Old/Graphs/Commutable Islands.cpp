bool compare(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
int find(int node,vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=find(parent[node],parent);
}

void Union(int u, int v, vector<int>&parent, vector<int>&rank){
    
    if(u==v){
        return;
    }
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int,vector<pair<int,int>>>adj;
    
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        int wt = B[i][2];
        
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>rank(A+1);
    vector<int>parent(A+1);
    
    for(int i=0; i<=A; i++){
        rank[i]=0;
        parent[i]=i;
    }
    sort(B.begin(),B.end(),compare);
    int minCost = 0;
    for(int i=0; i<B.size(); i++){
        
        int u = find(B[i][0],parent);
        int v = find(B[i][1],parent);
        int weight = B[i][2];
        
        if(u!=v){
            Union(u,v,parent,rank);
            minCost += weight;
        }
    }
    return minCost;
}
