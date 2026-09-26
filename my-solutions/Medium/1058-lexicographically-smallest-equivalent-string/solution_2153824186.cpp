class Solution {
    int parent[26];
    

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
        if(px != py){
            // union by value because we need the smallest character at the root
            if(px < py){
                parent[py] = px;
            }
            else{
                parent[px] = py;
            }
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        int n = s1.size();
        int m = baseStr.size();

       
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
      

        for(int i=0; i<n; i++){
            unite(s1[i] - 'a', s2[i] - 'a'); 
        }

        
        string ans = "";
        for(int i=0; i<m; i++){
            int indx = find(baseStr[i] - 'a');
            char c = indx + 'a';
           
            ans += c;
        }

        return ans;


        
    }
};