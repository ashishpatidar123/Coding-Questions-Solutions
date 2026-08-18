class Solution {
private:
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>& paths, vector<int>& path,vector<bool>&visited, int n ){
        if(node == n-1){
            paths.push_back(path);
            return;
        }

        visited[node] = true;

        for(auto v : graph[node]){
            if(!visited[v]){
                path.push_back(v);
                dfs(v, graph, paths, path,visited, n);
                path.pop_back();
                visited[v] = false;
            }
        }

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>>paths;
        vector<int>path;


        vector<bool>visited(n, false);
        path.push_back(0);
        dfs(0, graph, paths, path,visited, n);

        return paths;

    }
};
