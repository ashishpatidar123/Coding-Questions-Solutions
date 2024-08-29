class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph,vector<int>&visited,vector<int>&path,vector<int>&safe){
        
        visited[node]=1;
        path[node]=1;
        safe[node]=0;

        for(auto v:graph[node]){
            
            if(path[v]){
                safe[node]=0;
                return true;
            } 
            
            else if(visited[v]==0 && dfs(v,graph,visited,path,safe)){
                safe[node]=0;
                return true;
            }
        }
        safe[node]=1;
        path[node]=0;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>path(n,0);
        vector<int>safe(n,0);
        vector<int>visited(n,0);
        
        for(int i=0; i<n; i++){
            if(!visited[i]) dfs(i,graph,visited,path,safe);
        }

        vector<int>ans;

        for(int i=0; i<n; i++){
            if(safe[i]) ans.push_back(i);
        }

        return ans;

    }
};
