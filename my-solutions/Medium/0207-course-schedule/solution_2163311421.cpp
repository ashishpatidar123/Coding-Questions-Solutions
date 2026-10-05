class Solution {
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0; i<n; i++){
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];

            adj[second].push_back(first);
            indegree[first]++;
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        if(q.empty()){
            return false;
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(count < numCourses){
            return false;
        }
        return true;
        
        
    }
};