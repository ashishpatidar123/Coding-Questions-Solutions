class Solution {
public:
    bool diff(string& first, string& second){
        int n = 8;
        int count = 0;
        for(int i=0; i<n; i++){
            if(first[i] != second[i]){
                count++;
            }
        }
        if(count == 1){
            return true;
        }
        return false;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        // int n = bank.size();

        // unordered_map<string, vector<string>>graph;

        // for(int i=0; i<n; i++){
        //     if(bank[i] == startGene) continue;
        //     if(diff(startGene, bank[i])){
        //         graph[startGene].push_back(bank[i]);
        //         graph[bank[i]].push_back(startGene);
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(bank[i] == startGene || bank[j] == startGene) continue;
        //         if(diff(bank[i], bank[j])){
        //             graph[bank[i]].push_back(bank[j]);
        //             graph[bank[j]].push_back(bank[i]);
        //         }
        //     }
        // }

        // unordered_map<string, bool>visited;
        // queue<pair<string, int>>q;
        // int step = 0;

        // q.push({startGene,0});
        // visited[startGene] = true;

        // while(!q.empty()){
        //     auto entry = q.front();
        //     q.pop();
        //     string gene = entry.first;
        //     int step = entry.second;
        //     if(gene == endGene){
        //         return step;
        //     }

        //     for(string nbr : graph[gene]){
        //         if(visited.find(nbr) == visited.end()){
        //             visited[nbr] = true;
        //             q.push({nbr, step+1});
        //         }
        //     }
        // }

        // return -1;

        unordered_set<string>bankCheck(bank.begin(),bank.end()); // this if for checking valid genes in O(1)

        if(bankCheck.find(endGene) == bankCheck.end()) return -1; // if the endGene is not valid then we can mutate to it

        queue<string>q;
        q.push(startGene);

        int count = 0;
        char choices[] = {'A', 'C', 'G', 'T'};

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                string curr = q.front();
                q.pop();

                if(curr == endGene){
                    return count;
                }

                for(int j=0; j<8; j++){
                    char original = curr[j];

                    for(auto c : choices){
                        if(c == original) continue;

                        curr[j] = c;

                        if(bankCheck.count(curr)){
                            q.push(curr);
                            bankCheck.erase(curr); //removing so that it is marked as visited
                        }
                    }

                    curr[j] = original;
                }

               
            }
             count++;
        }

        return -1;
    }

};
