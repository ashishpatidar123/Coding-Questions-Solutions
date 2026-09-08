class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int count = 0;
        int n = s.length();
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                count++;
            }
        }
        if(count == k){
            ans++;
        }
        for(int l=1; l<=n-1; l++){
            int score = count;
            if(s[l-1] == s[l]){
                score--;
            }
            if(s[n-1] == s[0]){
                score++;
            }
            if(score == k){
                ans++;
            }
        }

        return ans;
    }
};