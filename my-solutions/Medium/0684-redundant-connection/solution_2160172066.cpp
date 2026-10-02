class Solution {
    int parent[1001];

    int find(int x){
        if(parent[x] == x){
            return parent[x];
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py){
            return true;
        }
        
        parent[py] = px;
        
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        
        for(int i=0; i<n; i++){
            parent[i+1] = i+1;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(unite(edges[i][0], edges[i][1])){
                ans = {edges[i][0], edges[i][1]};
                break;
            }
        }

        return ans;
        
        
    }
};