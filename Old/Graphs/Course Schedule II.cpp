class Solution {
    void topologicalSort(int node,unordered_map<int,bool>&visited, 
        unordered_map<int,vector<int>> &adj, stack<int>&st){

            visited[node]=true;

            for(auto neighbours:adj[node]){
                if(visited[neighbours]==false){
                    topologicalSort(neighbours,visited,adj,st);
                }
            }
            st.push(node);
        }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // perform the topological sort and check for the cycle
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];

            adj[second].push_back(first);
        }

        unordered_map<int,bool> visited;

        for(int i=0; i<numCourses; i++){
            visited[i]=false;
        }

        stack<int> st;

        for(int i=0; i<numCourses; i++){
            if(visited[i]==false){
                topologicalSort(i,visited,adj,st);
            }
        }
        vector<int> ans;
        vector<int> parent(numCourses);
        int index = 0;

        while(!st.empty()){
            parent[st.top()]=index;
            ans.push_back(st.top());
            st.pop();
            index++;
        }
        bool check = false;
        for(int i=0; i<numCourses; i++){
            for(auto j:adj[i]){

                if(parent[i]>parent[j]){
                    check = true;
                    return {};
                }
            }
        }
        return ans;
    }
};
