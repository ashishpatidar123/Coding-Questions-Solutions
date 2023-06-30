class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // creating a queue to store the word and the level at which we found that word
        queue<pair<string,int>>q;
        // push the begin word
        q.push({beginWord,1});
        // create a set so that we can easily find and delete an item
        unordered_set<string>st(wordList.begin(),wordList.end());
        // erase the beginword if it is present in the set
        st.erase(beginWord);
        // run the loop until the queue is empty
        while(!q.empty()){
            // take out the front element of the queue
            string word = q.front().first;
            int path = q.front().second;
            q.pop();
            // if it's the end word then return the path length
            if(word==endWord){
                return path;
            }
            // else replace each character of the word with all the letters from a to z and
            // check if the newly formed word is in the set or not
            // if it's in the set then remove it from the set because we already processed this
            // ans push it into the queue along with the path length increased by 1
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,path+1});
                    }
                }
                // replace the character with the original character of the word;
                word[i]=original;
            }
        }
        return 0;
    }
};
