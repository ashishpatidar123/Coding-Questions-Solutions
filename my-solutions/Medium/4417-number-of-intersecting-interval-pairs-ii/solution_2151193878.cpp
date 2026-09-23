class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        long long int count = 0;
        long long int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<long long int> starts;
        for(long long int i = 0; i < n; i++){
            starts.push_back(intervals[i][0]);
        }

        for(long long int i = 0; i < n; i++){
            long long int end_1 = intervals[i][1];
            auto it = upper_bound(starts.begin(), starts.end(), end_1);
            long long int temp = it - starts.begin(); // this will give the number of elements less than or equal to end_1, i.e. time intervals starting before end_1 so overlapping
            count += temp - i -1; // removing the intervals which are counted twice, i.e before i and i;
        }

        return count;
        
    }
};