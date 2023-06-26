// Approach 1
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

// Approach 2
// Neetcode solution
#include <bits/stdc++.h> 
int minimumCost(vector<vector<int>> &coordinates, int n)
{   
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=0; i<n; i++){
        int x1 = coordinates[i][0];
        int y1 = coordinates[i][1];
        for(int j=i+1; j<n; j++){
            int x2 = coordinates[j][0];
            int y2 = coordinates[j][1];
            int distance = abs(x1-x2) + abs(y1-y2);
            adj[i].push_back({distance,j});
            adj[j].push_back({distance,i});
        }
    }
    int minCost = 0;
    unordered_map<int,bool>visit;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    int count = 0;
    while(count<n){
        pair<int,int>temp = pq.top();
        pq.pop();
        int u = temp.second;
        int cost = temp.first;
        
        if(visit[u]==true){
            continue;
        }
        visit[u]=true;
        count++;
        minCost += cost;
        for(auto v:adj[u]){
            int wt = v.first;
            if(visit[v.second]!=true){
                pq.push({wt,v.second});
            }
        }
    }
    return minCost;
}

// Approach 3
/*
    Time Complexity  :   O(N ^ 2)
    Space Complexity :   O(N)

    Where ‘N’ is the size of ‘coordinates’ array.
*/

#include <climits>

int minimumCost(vector<vector<int>> &coordinates, int n)
{
    int result = 0, count = 0;

    vector<bool> visited(n);
    vector<int> cost(n, INT_MAX);

    // Index of source vertex.
    int src = 0;

    // Processing edges till 'n - 1' edges are included in the MST.
    while (count < n - 1)
    {
        visited[src] = true;
        cost[src] = INT_MAX;

        // To store the index of minimum cost vertex from 'src'.
        int nextMin = src;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
            {
                continue;
            }

            int distance = abs(coordinates[i][0] - coordinates[src][0]) + abs(coordinates[i][1] - coordinates[src][1]);

            // Relax the cost of edge connecting 'i' and 'src'.
            cost[i] = min(cost[i], distance);

            // Update the index of minimum cost vertex.
            if (cost[nextMin] > cost[i])
            {
                nextMin = i;
            }
        }

        result = result + cost[nextMin];

        // Update the source by index of minimum cost vertex from 'src' for next iteration.
        src = nextMin;

        count++;
    }
    return result;
}
