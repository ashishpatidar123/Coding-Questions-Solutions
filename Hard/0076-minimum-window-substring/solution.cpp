class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        

        unordered_map<char,int>val;

        for(int i=0; i<n; i++){
            val[t[i]]++;
        }

        int l=0;
        int r=0;

        int len = INT_MAX;
        unordered_map<char,int>count;
        int formed = 0;
        int required = val.size();
        int start = 0;

        while(r < m){

            count[s[r]]++;

            if((val.find(s[r])!=val.end()) &&( count[s[r]] == val[s[r]])){
                formed++;
            }

            while((l <= r) && (formed==required)){
                if(r-l+1 < len){
                    len = r-l+1;
                    start = l;
                }

                count[s[l]]--;
                if((val.find(s[l])!=val.end()) && (count[s[l]] < val[s[l]])){
                    formed--;
                }

                l++;
            }
            r++;


        }
        
        if(len == INT_MAX){
            return "";
        }
        return s.substr(start, len);

    }
};
