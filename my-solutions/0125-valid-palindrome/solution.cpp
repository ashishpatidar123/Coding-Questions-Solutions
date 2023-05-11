class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ans;
        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' && s[i]<='Z'){
               ans.push_back(s[i]-'A'+'a');
            }
            if(s[i]>='0' && s[i]<='9'){
                ans.push_back(s[i]);
            }
            if(s[i]>='a' && s[i]<='z'){
                ans.push_back(s[i]);
            }
        }
        int start = 0;
        int end = ans.size()-1;
        while(start<end){
            if(ans[start++]!=ans[end--]){
                return false;
            }
        }
        return true;
    }
};
