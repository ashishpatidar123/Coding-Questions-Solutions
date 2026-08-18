class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // so the basic idea of the approach is to detect if any cycle
        // is present in the graph or not
        // since we're talking about the prereq of the courses which 
        // itself says that the graph is a directed graph
        // We first try to find a topological sort
        // if we get a valid topological sort then we return true
        // else return false
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];

            adj[second].push_back(first);
        }

        vector<int> indegree(numCourses);

        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            
                for(auto j:adj[front]){
                    
                    indegree[j]--;
                    if(indegree[j]==0){
                        q.push(j);
                        
                    }
                }

        }
        if(count==numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};
