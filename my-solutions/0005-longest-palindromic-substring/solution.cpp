class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int left = 0;
        int right = n-1;
        int max_len = 0;
        for(int c = 0; c < 2*n-1; c++){
            int l = c/2;
            int r = l + c%2;

            while(l>=0 && r<n && s[l]==s[r]){
                int len = r-l+1;
                if(len > max_len){
                    max_len = len;
                    left = l;
                    right = r;
                }
                r++;
                l--;
            }
        }
        string ans = "";
        for(int i=left; i<=right; i++){
            ans += s[i];
        }
        return ans;
    }
};
