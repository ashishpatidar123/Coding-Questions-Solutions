class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state){
        if(state[node] == 1){
            return false; // visiting and we found a cycle
        }
        if(state[node] == 2){
            return true; // already marked safe
        }

        state[node] = 1; // visiting

        for(int v : graph[node]){
            if(!dfs(v, graph, state)){
                return false;
            }
        }

        state[node] = 2; // safe marked
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){

        int n = graph.size();
        // cycle detection logic only
        vector<int>state(n, 0);
        vector<int>safe;

        for(int i=0; i<n; i++){
            if(dfs(i, graph, state)){
                safe.push_back(i);
            }
        }
        

        return safe;
    }
};
