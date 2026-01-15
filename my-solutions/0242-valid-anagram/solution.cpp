class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        if(n != m){
            return false;
        }

        vector<int>count1(26,0);
        vector<int>count2(26,0);

        for(int i=0; i<n; i++){
            count1[s[i]-'a']++;
        }
        for(int i=0; i<m; i++){
            count2[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
        
    }
};
