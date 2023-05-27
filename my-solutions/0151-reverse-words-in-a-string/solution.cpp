class Solution {
public:
    
    string reverseWords(string s) {
        
        vector<string> store;
        // string s = "the   sky  is blue  ";
        int start = 0;
        for(int i =0; i<s.length(); i++){
            if(s[i]!=' '){
                start = i;
                break;
            }
        }
        int end = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]!=' '){
                end = i;
                break;
            }
        }
        string temp = "";
        for(int i = start; i<=end; i++){
            if(s[i]!=' '){
                temp = temp + s[i];
            }
            else {
                if(temp.size()!=0){
                    store.push_back(temp);
                    temp = "";
                }
                
            }
        }
        store.push_back(temp);
        // for(int i=0; i<store.size(); i++){
        //     cout<<store[i]<<" ";
        // }
        string ans = "";
        for(int i = store.size()-1; i>=0; i--){
            ans = ans + store[i];
            if(i!=0){
                ans = ans + ' ';
            }
        }
        // cout<<ans;
    return ans;
    }
};
