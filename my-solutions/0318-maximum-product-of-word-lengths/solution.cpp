class Solution {
public:
    int maxProduct(vector<string>& words) {

        int n = words.size();
        // vector<vector<int>>mask(n, vector<int>(26,0));
        // for(int i=0; i<n; i++){
        //     string s = words[i];
            
        //     for(int j=0; j<s.size(); j++){
        //         mask[i][s[j]-'a'] = 1;
        //     }

        // }

        // int ans = 0;

        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){

        //         bool check = true;
        //         for(int l=0; l<26; l++){
        //             if((mask[i][l] & mask[j][l]) == 1){
        //                 check = false;
        //                 break;
        //             }
        //         }
        //         if(check){
        //             int len1 = words[i].size();
        //             int len2 = words[j].size();

        //             ans = max(ans, len1*len2);
        //         }
        //     }
        // }

        // return ans;

        // creating bitmask for letters
        vector<int>mask(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(char c:words[i]){
                // setting the bit corresponding to that letter
                mask[i] = mask[i] | (1 << (c - 'a')); 
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((mask[i]&mask[j]) == 0){
                    int len1 = words[i].size();
                    int len2 = words[j].size();

                    ans = max(ans, len1*len2);
                }
            }
        }
        return ans;
    }
};
