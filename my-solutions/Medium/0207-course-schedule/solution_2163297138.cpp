class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& color){
        if(color[node] == 1){
            return true;
        }
        color[node] = 1;
        for(auto v: adj[node]){
            if(color[v] == 1){
                return true;
            }
            else if(color[v] == 0){
                if(dfs(v, adj, color)){
                    return true;
                }
            }
        }
        color[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);

        for(int i=0; i<n; i++){
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];

            adj[second].push_back(first);
        }

        vector<int>color(numCourses,0);
        for(int i=0; i<numCourses; i++){
            if(color[i] == 0){
                bool check = dfs(i, adj, color);
                if(check){
                    return false;
                }
            }
        }

        return true;
        
    }
};