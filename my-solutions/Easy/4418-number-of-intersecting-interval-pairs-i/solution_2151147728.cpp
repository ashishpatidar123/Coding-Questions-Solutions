class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {

        int count = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                int start_1 = intervals[i][0];
                int end_1 = intervals[i][1];

                int start_2 = intervals[j][0];
                int end_2 = intervals[j][1];

                if(start_2 <= end_1){
                    count++;
                }

            }
            
        }

        return count;
        
    }
};