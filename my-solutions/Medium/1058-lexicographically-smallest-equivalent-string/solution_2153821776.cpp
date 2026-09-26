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
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        int n = s1.size();
        int m = baseStr.size();

        parent.resize(26);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        rank.assign(26, 0); // rank array - height of the tree

        for(int i=0; i<n; i++){
            unite(s1[i] - 'a', s2[i] - 'a'); 
        }

        unordered_map<int, vector<char>> roots;
        for(int i=0; i<26; i++){
            roots[find(i)].push_back(i + 'a');

        }
        for(auto& [id, list] :  roots){
            sort(list.begin(), list.end());
        }
        string ans = "";
        for(int i=0; i<m; i++){
            int indx = find(baseStr[i] - 'a');
            char c = roots[indx][0];
           
            ans += c;
        }

        return ans;


        
    }
};