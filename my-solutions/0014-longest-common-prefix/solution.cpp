class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";

        int n = strs.size();
        if(n==1){
            return strs[0];
        }
        // sort(strs.begin(),strs.end());

        string first = strs[0];
        int l = first.size();
       
        bool flag = true;
        for(int i=0; i<l; i++){

            char c = first[i];

            for(int j=1; j<n; j++){

                if(strs[j].size() > i){
                    if(strs[j][i] != c){
                        flag = false;
                        break;
                    }
                    
                }
                else{
                    return ans;
                }

            }
            if(flag){
                ans += c;
            }
            else{
                return ans;
            }

        }
        
        return ans;
    }
};
