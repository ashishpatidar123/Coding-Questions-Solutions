class Solution {
public:
    
    void dfs(int node, vector<bool>&visited, vector<vector<int>>&rooms){
        visited[node]=true;

        for(auto nbr: rooms[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,rooms);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        dfs(0,visited,rooms);
        bool ans = false;
        for(bool check:visited){
            if(check==false){
                return false;
            }
        }
        return true;
    }
};
