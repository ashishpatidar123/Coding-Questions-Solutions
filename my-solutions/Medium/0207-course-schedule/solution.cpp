class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);

        int m = prerequisites.size();

        for(int i=0; i<m; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            if(v==u){
                return false;
            }
            adj[v].push_back(u);
        }
        
        if(m==1 || m==0){
            return true;
        }
        
        queue<int>q;
       
        for(int k=0; k<numCourses; k++){
            vector<int>visited(numCourses,0);
            q.push(k);
            visited[k]=1;
            
            while(!q.empty()){

                int u = q.front();
                q.pop();
                for(auto v:adj[u]){
                    if(visited[v] && v==k){
                        return false;
                    }
                    if(!visited[v]){
                        q.push(v);
                        visited[v]=true;
                    }
                }
            }
        }

        return true;

    }
};
