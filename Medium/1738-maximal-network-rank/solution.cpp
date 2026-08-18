class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        int m = roads.size();

        vector<int>count(n, 0);

        for(int i=0; i<roads.size(); i++){
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }

        vector<vector<int>>adj(n, vector<int>(n,0));

        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]][roads[i][1]] = 1;
            adj[roads[i][1]][roads[i][0]] = 1;
        }
        int maxi = -1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int total = count[i] + count[j];
                if(adj[i][j] == 1){
                    total--;
                }
                maxi = max(total, maxi);
            }
        }

        return maxi;



        
    }
};
