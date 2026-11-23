class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        int m  = times.size();

        vector<vector<pair<int,long long>>>adj(n+1);

        for(int i=0; i<m; i++){
            int u = times[i][0];
            int v = times[i][1];
            long long w = times[i][2];

            adj[u].push_back({v,w});
        }

        vector<long long>dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            
            if(d != dist[u]) continue;

            for(auto [v, w] : adj[u]){
                long long newd = dist[u] + w;

                if(newd < dist[v]){
                    dist[v] = newd;
                    pq.push({dist[v], v});
                }
            }

        }

        long long int ans = -1;

        for(int i=1; i<=n; i++){
            ans = max(ans, dist[i]);
        }
        if(ans == INT_MAX) return -1;
        return ans;


    }
};