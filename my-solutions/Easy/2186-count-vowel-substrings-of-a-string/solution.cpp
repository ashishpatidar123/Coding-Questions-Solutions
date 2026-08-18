class Solution {
public:
    bool check(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;   
        }
        return false;
    }
    int solve(string word, int k){

        int n = word.size();
        unordered_map<char, int>freq;
        int l = 0;
        int ans = 0;
        int distinct = 0;

        for(int r=0; r<n; r++){

            char c = word[r];

            if(!check(c)){
                freq.clear();
                distinct = 0;
                l = r+1;
                continue;
            }

            freq[c]++;

            if(freq[c] == 1){
                distinct++;
            }

            while(distinct > k){

                freq[word[l]]--;

                if(freq[word[l]] == 0){
                    distinct--;
                }

                l++;

            }
            ans += r - l+1;

        }
        return ans;

    }
    int countVowelSubstrings(string word) {

        return solve(word, 5) - solve(word, 4);
        
        
    }
};
