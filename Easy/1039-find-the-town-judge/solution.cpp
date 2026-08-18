class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        int m = trust.size();

        vector<int>indegree(n,0);
        vector<int>outdegree(n, 0);

        for(int i=0; i<m; i++){
            indegree[trust[i][1]-1]++;
            outdegree[trust[i][0]-1]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i+1;
            }
        }

        return -1;

        
        
    }
};
