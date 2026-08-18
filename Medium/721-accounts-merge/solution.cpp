class Solution {
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]){
            swap(px, py);
        }
        parent[py] = px;

        if(rank[px] == rank[py]){
            rank[px]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> index;
        unordered_map<string, string>names;

        int id = 0;

        for(auto& acc:accounts){
            string name = acc[0];
            for(int i=1; i<acc.size(); i++){
                if(index.find(acc[i]) == index.end()){
                    index[acc[i]] = id++;
                }
                names[acc[i]] = name;
            }
        }


        parent.resize(id);
        rank.resize(id, 0);
        iota(parent.begin(), parent.end(),0);

        for(auto& acc:accounts){
            int first = index[acc[1]];

            for(int i=2; i<acc.size(); i++){
                unite(first, index[acc[i]]);
            }
        }

        unordered_map<int, vector<string>> roots;
        for(auto& [email, id] :  index){
            roots[find(id)].push_back(email);

        }

        vector<vector<string>> result;
        for(auto& [root, emails] : roots){
            sort(emails.begin(), emails.end());
            string name = names[emails[0]];
            emails.insert(emails.begin(), name);
            result.push_back(emails);
        }

        return result;

        

        

        
        
    }
};