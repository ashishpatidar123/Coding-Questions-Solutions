class Solution {
    vector<int>parent;
    vector<int>rank;
    bool check(string s1, string s2){
        int count = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) count++;
            if(count > 2) return false;
        }

        return true;
    }

    int find(int x){
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
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        unordered_map<string, int> index;
        int idx = 0;
        for(int i=0; i<n; i++){
            if(index.find(strs[i]) == index.end()){
                index[strs[i]] = idx;
                idx++;
            }
        }
        parent.resize(idx); //parent array
        rank.resize(idx, 0); // rank array - height of the tree
        iota(parent.begin(), parent.end(),0);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(check(strs[i], strs[j])){
                    unite(index[strs[i]], index[strs[j]]);
                }
            }
        }

        set<int>s;

        for(int i=0; i<n; i++){
            int p = find(index[strs[i]]);
            s.insert(p);
        }

        return s.size();

        
    }
};