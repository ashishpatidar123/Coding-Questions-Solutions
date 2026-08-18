class Solution {
public:
    int minimizeSum(vector<int>& a) {
        int n = a.size();
        if(n==3){
            return 0;
        }
        sort(a.begin(),a.end());
        int one = a[n-1] - a[2];
        int two = a[n-3] - a[0];
        int three = a[n-2] - a[1];
        return min({one,two,three});
    }
};
