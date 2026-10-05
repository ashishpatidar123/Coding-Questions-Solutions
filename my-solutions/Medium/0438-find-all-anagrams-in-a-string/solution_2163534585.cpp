class Solution {
    bool check(vector<int>& freq, vector<int>& window){
        for(int i=0; i<26; i++){
            if(freq[i] != window[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {

        int m = s.length();
        int n = p.length();

        vector<int>freq(26,0);
        vector<int>window(26,0);
        if( n > m) return {}; 
        for(int i=0; i<n; i++){
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        vector<int>ans;

        for(int i=0; i<=m-n; i++){
            
            if(i >= 1 ){
                window[s[i-1] - 'a']--;
                window[s[i+n-1] - 'a']++;
            }
            if(check(freq, window)){
                ans.push_back(i);
            }

        }
        return ans;
        
    }
};