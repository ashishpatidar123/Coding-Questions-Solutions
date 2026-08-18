class Solution {

    static bool compare(vector<int>&a, vector<int>&b){
        return a[2]<b[2];
    }
    int find(int node, vector<int>&parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find(parent[node],parent);
    }
    
    void Union(int u, int v, vector<int>&parent, vector<int>&rank){
        u = find(u,parent);
        v = find(v,parent);
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
    int distance(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        // using kruskal's algorithm
        int v = p.size();
        vector<int>parent(v);
        vector<int>rank(v);
        for(int i=0; i<v; i++){
            rank[i]=0;
            parent[i]=i;
        }
        // sinces edges are not there 
        // so first we create edges
        vector<vector<int>> edges;
        for(int i=0; i<v; i++){
            for(int j=i+1; j<v; j++){
                vector<int> temp(3);
                temp[0] = i;
                temp[1] = j;
                temp[2] = distance(p[i][0],p[i][1],p[j][0],p[j][1]);
                edges.push_back(temp);

            }
        }
        int minWeight = 0;
        sort(edges.begin(),edges.end(),compare);
        for(int i=0; i<edges.size(); i++){
            int u = find(edges[i][0],parent);
            int v = find(edges[i][1],parent);
            int weight = edges[i][2];
            if(u==v){
                continue;
            }
            if(u!=v){
                Union(u,v,parent,rank);
                minWeight+=weight;
            }
        }
        return minWeight;
    }
};
