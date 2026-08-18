class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int>arr(58);
        for(int i=0; i<n; i++){
            arr[s[i]-'A']++;
        }
        int ans = 0;
        int flag = 0;
        for(int i=0; i<58; i++){
            if(arr[i]%2!=0){
                flag =1;
            }
            ans += arr[i] - arr[i]%2;
        }
        return ans+flag;
    }
};
