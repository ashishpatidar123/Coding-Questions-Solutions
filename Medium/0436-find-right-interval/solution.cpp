class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        vector<pair<int,int>>start(n);

        for(int i=0; i<n; i++){
            start[i].first = intervals[i][0];
            start[i].second = i;
        }
        sort(start.begin(),start.end());

        vector<int>ans;

        for(int i=0; i<n; i++){

            int end = intervals[i][1];

            int left = 0;
            int right = n-1;
            int index = INT_MAX;

            while(left<=right){

                int mid = left + (right-left)/2;
            
                if(start[mid].first >= end){
                    index = min(index,start[mid].second);
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            if(index==INT_MAX){
                index = -1;
            }
            ans.push_back(index);
        }

        return ans;
    }
};
