class Solution {
public:
    bool check(string s){
        int n = s.size();
        int i=0;
        int j = n-1;

        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {

        int n = s.size();
        int ans = 0;
        // for(int i=0; i<n; i++){
        //     for (int len = 1; len <= n - i; len++){
        //         string t = s.substr(i, len);
        //         if(check(t)){
        //             ans++;
        //         }
        //     }    
        // }
        

        for(int c = 0; c < 2*n-1; c++){
            int l = c/2;
            int r = l + c%2;

            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                r++;
                l--;
            }
        }
        return ans;
        
    }
};
