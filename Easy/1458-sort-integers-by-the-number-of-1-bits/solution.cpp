class Solution {
public:
    static int countBits(int n) {
        return __builtin_popcount(n);       // for int
        // return __builtin_popcountll(n);  // for long long
        }
    static bool comp(int a, int b){
        int acount = countBits(a);
        int bcount = countBits(b);
        if(acount == bcount){
            return a < b;
        }
        return acount < bcount;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        int n = arr.size();

        sort(arr.begin(),arr.end(), comp);

        return arr;
    }
};
