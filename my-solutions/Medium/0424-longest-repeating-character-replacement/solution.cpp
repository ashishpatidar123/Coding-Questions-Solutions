class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int ans = 0;
        set<char>st;
        for(int i=0; i<n; i++){
            st.insert(s[i]);
        }
        for(char c='A'; c<='Z'; c++){

            int count = 0;
            int l=0;
            int r=0;
            if(st.find(c) != st.end()){
                while(r<n){
                    if(s[r] != c){
                        count++;
                    }

                    if(count > k){
                        if(s[l]!=c){
                            count--;
                        }
                        l++;
                    }
                    int len = r-l+1;
                    ans = max(ans, len);
                    r++;
                }
            }

        }

        return ans;

        
    }
};
