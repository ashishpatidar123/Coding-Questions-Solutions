class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        int n = words.size();

        vector<vector<int>>count(n, vector<int>(26,0));
        string word = words[0];
        int m = word.length();

        for(int j=0; j<m; j++){
            count[0][word[j]-'a']++;
        }
        vector<string>ans;
        ans.push_back(words[0]);

        for(int i=1; i<n; i++){

            string word = words[i];
            int m = word.length();

            for(int j=0; j<m; j++){
                count[i][word[j]-'a']++;
            }
            for(int j=0; j<26; j++){
                if(count[i][j] != count[i-1][j]){
            
                    ans.push_back(words[i]);
                    break;
                }
            }

        }
        return ans;

    }
};
