class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int>index;
        int maxi=0;
        int idx = 0;
        for(int i=0; i<n; i++){

            if(index.find(s[i]) == index.end() || index[s[i]] < idx){
                index[s[i]] = i;
                int len = i-idx+1;
                maxi = max(maxi, len);
            }
            else{
                int len = i-idx;
                idx = index[s[i]]+1;
                index[s[i]] = i;
                maxi = max(len, maxi);
            }
        }
        // int len = n-idx;
        // maxi = max(maxi, len);
        return maxi;
    }
};
