class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        
        using pii = pair<int,int>;
        priority_queue<pair<int, pii>>pq;
        int n = points.size();
        for(int i=0; i<n; i++){

            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            pq.push({dist, {x,y}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;

        while(!pq.empty()){

            pair<int,pii> p = pq.top();
            pq.pop();

            vector<int>temp;
            temp.push_back(p.second.first);
            temp.push_back(p.second.second);
            ans.push_back(temp);

        }
        return ans;

    }
};
