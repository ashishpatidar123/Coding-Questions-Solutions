class Solution {
private:

    void dfs(string& curr, string& beginWord, vector<string>&path, unordered_map<string, vector<string>>& parents, vector<vector<string>>& result){

        if(curr == beginWord){
            vector<string>currPath = path;
            reverse(currPath.begin(), currPath.end());
            result.push_back(currPath);
            return;
        }

        for(string& parent : parents[curr]){
            path.push_back(parent);
            dfs(parent, beginWord, path, parents, result);
            path.pop_back();
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // unordered_set<string>wordCheck(wordList.begin(), wordList.end());

        // vector<vector<string>>result;

        // queue<vector<string>>q;
        // q.push({beginWord});
        // bool found = false;

        // while(!q.empty() && !found){
        //     int size = q.size();

        //     unordered_set<string>visited;

        //     for(int i=0; i<size; i++){
        //         vector<string>path = q.front();
        //         q.pop();

        //         string curr = path.back(); //last gene


        //         for(int j=0; j<curr.size(); j++){
        //             char original = curr[j];

        //             for(char c='a'; c<='z'; c++){
        //                 if(c == original) continue;

        //                 curr[j] = c;

        //                 if(wordCheck.count(curr)){
        //                     visited.insert(curr);

        //                     vector<string>newPath = path;

        //                     newPath.push_back(curr);

        //                     if(curr == endWord){
        //                         found = true;
        //                         result.push_back(newPath);
        //                     }
        //                     else{
        //                         q.push(newPath);
        //                     }
        //                 }
                      
        //             }
        //             curr[j] = original;
        //         }
        //     }
        //     for( auto c : visited){
        //         wordCheck.erase(c);
        //     }
        // }

        // return result;


        unordered_set<string>wordCheck(wordList.begin(), wordList.end());
        vector<vector<string>>result;

        if(wordCheck.find(endWord) == wordCheck.end()){
            return result;
        }

        unordered_map<string, vector<string>>parents;

        queue<string>q;
        q.push(beginWord);
        wordCheck.erase(beginWord);
        bool found = false;

        while(!q.empty() && !found){

            int size = q.size();

            unordered_set<string>visited;

            for(int i=0; i<size; i++){

                string curr = q.front();
                q.pop();
                string word = curr;

                for(int j=0; j<word.size(); j++){
                    char original  = word[j];

                    for(char c = 'a'; c<= 'z'; c++){
                        if(c == original ) continue;

                        word[j] = c;

                        if(wordCheck.count(word)){
                            visited.insert(word);
                            parents[word].push_back(curr);

                            if(word == endWord){
                                found = true;
                            }
                        }

                    }

                    word[j] = original;
                }

            }

            for(auto s : visited){
                wordCheck.erase(s);
                q.push(s);
            }

        }

        if(found){
            vector<string>path;
            path.push_back(endWord);
            dfs(endWord, beginWord, path, parents, result);
        }

        return result;

    }
};
