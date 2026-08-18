class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>wordCheck(wordList.begin(), wordList.end());

        if(wordCheck.find(endWord) == wordCheck.end()){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int count = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    return count+1;
                }
                for(int j=0; j<word.size(); j++){
                    char original = word[j];

                    for(char c='a'; c<='z'; c++){
                        if(c == original) continue;

                        word[j] = c;

                        if(wordCheck.count(word)){
                            q.push(word);
                            wordCheck.erase(word);
                        }
                      
                    }
                    word[j] = original;
                }
            }
            count++;
        }

        return 0;
    }
};
