class Solution {
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        // move up in the tree to reach the root node, because root node has parent equal to itself
        // also while doing this map each node to root only
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        // if both belongs to same set then no unite
        if(px == py) return;
        // check the height of the trees, we will add the smaller to larger one
        if(rank[px] < rank[py]){
            swap(px, py);
        }
        // now make the parent of smaller tree as large tree
        parent[py] = px;
        // if their current ranks are same then on addition rank (height increases by 1)
        if(rank[px] == rank[py]){
            rank[px]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> index; // mapping each email to an index value
        unordered_map<string, string>names; // mapping each email to it's owner name

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


        parent.resize(id); //parent array
        rank.resize(id, 0); // rank array - height of the tree
        iota(parent.begin(), parent.end(),0); // setting parent to all indexes to 0 so currently each
        // email belongs to a seperate set

        for(auto& acc:accounts){
            int first = index[acc[1]];
            // taking the first email's index from each list
            for(int i=2; i<acc.size(); i++){
                // adding all other emails to this first email set, because they all belong
                // to the same person
                unite(first, index[acc[i]]);
            }
        }

        unordered_map<int, vector<string>> roots;
        // now we will mow find all these new sets
        for(auto& [email, id] :  index){
            // for each email, id pair, we will store them in the common vector based on parent's index
            // they share same parent
            roots[find(id)].push_back(email);

        }

        vector<vector<string>> result; // result creation
        for(auto& [root, emails] : roots){
            // sort emails first
            sort(emails.begin(), emails.end());
            // now use the names mapping to find the name of the owner - can use any email 
            string name = names[emails[0]];
            // add that name to the first position to frame the output
            emails.insert(emails.begin(), name);
            // push it into the result
            result.push_back(emails);
        }

        return result;

        

        

        
        
    }
};