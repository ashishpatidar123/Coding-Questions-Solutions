class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int>order;
        if(q.empty()){
            return {};
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(order.size() < numCourses){
            return {};
        }
        return order;
    }
};