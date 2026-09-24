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
    bool equationsPossible(vector<string>& equations) {

        int n = equations.size();
        
        parent.resize(26);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        rank.assign(26, 0); // rank array - height of the tree

        for(int i=0; i<n; i++){
            char x = equations[i][0];
            char y = equations[i][3];
            char sign = equations[i][1];

            if(sign == '='){
                unite(x - 'a', y - 'a');
            }
        }

        
        for(int i=0; i<n; i++){
            char x = equations[i][0];
            char y = equations[i][3];
            char sign = equations[i][1];

            if(sign == '!'){
                int px = find(x - 'a');
                int py = find(y - 'a');

                if(px == py){
                    return false; 
                }
            }
        }
        return true;
        
        
    }
};