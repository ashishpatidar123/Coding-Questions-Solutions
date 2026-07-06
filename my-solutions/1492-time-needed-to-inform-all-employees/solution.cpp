// class Solution {
// public:
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
//         vector<vector<int>>graph(n);

//         for(int i=0; i<n; i++){
//             if(i != headID){
//                 graph[manager[i]].push_back(i);
//             }
//         }

//         vector<int>visited(n, false);

//         vector<int>time(n, -1);

//         time[headID] = 0;

//         queue<int>q;
//         q.push(headID);

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             visited[node] = true;
//             for(auto v : graph[node]){
//                 if(!visited[v]){
//                     time[v] = time[node] + informTime[node];
//                     q.push(v);
//                 }
//             }
//         }

//         int ans = -1;

//         for(int i=0; i<n; i++){
//             ans = max(ans, time[i]);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> timeNeeded(n, -1);
        int maxTime = 0;
        
        for (int i = 0; i < n; i++) {
            maxTime = max(maxTime, getInformedTime(i, manager, informTime, timeNeeded));
        }
        
        return maxTime;
    }

private:
    int getInformedTime(int i, const vector<int>& manager, const vector<int>& informTime, vector<int>& timeNeeded) {

        if(manager[i] == -1){
            return 0;
        }
        if(timeNeeded[i] != -1){
            return timeNeeded[i];
        }
       
        timeNeeded[i] = getInformedTime(manager[i], manager, informTime, timeNeeded) + informTime[manager[i]];
        
        return timeNeeded[i];
    }
};

