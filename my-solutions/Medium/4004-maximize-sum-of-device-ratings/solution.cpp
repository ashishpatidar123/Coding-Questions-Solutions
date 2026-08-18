class Solution {
public:
    
    
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        
        if(n == 1){
            long long total = 0;
            for(int i=0; i<m; i++){
                total += units[i][0];
            }
            return total;
        }
        int globalMini = INT_MAX;
        int mini2Mini = INT_MAX;
        long long total = 0;

        for(int i=0; i<m; i++){
            int mini1 = INT_MAX;
            int mini2 = INT_MAX;

            for(int j=0; j<n; j++){
                if(units[i][j] < mini1){
                    mini2 = mini1;
                    mini1 = units[i][j];
                }
                else if(units[i][j] < mini2){
                    mini2  = units[i][j];
                }
            }
            total += mini2;
            mini2Mini = min(mini2Mini, mini2);
            globalMini = min(globalMini, mini1);

        }
        total = total - mini2Mini + globalMini;
        return total;

    }
};
