class Solution {
    int find(int x, vector<int>&parent){
        if(parent[x] == x){
            return parent[x];
        }
        return parent[x] = find(parent[x], parent);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int>parent(n);
        vector<int>size(n,1);
        vector<int>count(n,0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(const auto& edge : edges){
            int px = find(edge[0], parent);
            int py = find(edge[1], parent);

            if(px != py){
                parent[px] = py;
                size[py] += size[px];
                count[py] += count[px] + 1;
            }
            else{
                count[py]++;
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            if(parent[i] == i){
                if(count[i] == (size[i]*(size[i]-1))/2){
                    ans++;
                }
            }
        }

        return ans;

        
    }
};