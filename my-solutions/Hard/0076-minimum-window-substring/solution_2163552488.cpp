class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        if( n > m) return "";

        for(int i=0; i<n; i++){
            need[t[i]]++;
        }

        int left = 0;
        int formed = 0;
        int required = need.size();

        string ans = "";
        int mini = INT_MAX;
        int start = 0;
        for(int right=0; right<m; right++){
            window[s[right]]++;

            if(need.find(s[right]) !=  need.end() && window[s[right]] == need[s[right]]){
                formed++;
            }

            while(formed == required){
                

                if(right - left + 1 < mini){
                    mini = right - left + 1;
                    start = left;
                }
                window[s[left]]--;
                if(need.find(s[left]) !=  need.end() && window[s[left]] < need[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        ans = s.substr(start, mini);
        if(mini == INT_MAX) return "";
        return ans;


        
    }
};