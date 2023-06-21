class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        // unordered_map<int,bool> visited;
        // for(int i=0; i<numCourses; i++){
        //     visited[i] = false;
        // }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            // if(visited[front]==false){
            //     visited[front]=true;

                for(auto j:adj[front]){
                    
                    indegree[j]--;
                    if(indegree[j]==0){
                        q.push(j);
                        // visited[j]=true;
                    }
                }
            // }

        }
        if(count==numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};

