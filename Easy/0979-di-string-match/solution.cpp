class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int smaller = 0;
        int greater = n;
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            if(s[i]=='I'){
                ans.push_back(smaller++);
            }
            else{
                ans.push_back(greater--);
            }
        }
        ans.push_back(smaller);
        return ans;
    }
};
