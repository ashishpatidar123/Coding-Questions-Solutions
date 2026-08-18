class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        
        int n = occupiedIntervals.size();

        vector<vector<int>>intervals;

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];

        for(int i=1; i<n; i++){
            
            if(end == occupiedIntervals[i][0] - 1){
                end = max(end, occupiedIntervals[i][1]);
            }
            else if(end >= occupiedIntervals[i][0]){
                end = max(end, occupiedIntervals[i][1]);
            }
            else if(occupiedIntervals[i][0] > end){
                intervals.push_back({start, end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }
        intervals.push_back({start, end});

        int t = intervals.size();

        vector<vector<int>>ans;

        for(int i=0; i<t; i++){
            if(intervals[i][1] < freeStart){
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            if(intervals[i][1] >= freeStart && intervals[i][0] < freeStart){
                ans.push_back({intervals[i][0], freeStart-1});
            }
            if(intervals[i][0] > freeEnd){
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            if(intervals[i][0] <= freeEnd && intervals[i][1] > freeEnd){
                ans.push_back({freeEnd+1, intervals[i][1]});
            }
        }
        return ans;
    }
};
