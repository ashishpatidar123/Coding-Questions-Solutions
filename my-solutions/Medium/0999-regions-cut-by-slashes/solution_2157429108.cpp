class Solution {
    int index(int n, int i, int j, int num){
        return (n*i + j) * 4 + num;
    }
    int find(vector<int>&parent , int x){
        if(parent[x]== -1){
            return x;
        }
        return parent[x] = find(parent, parent[x]);
    }
    int unite(vector<int>&parent, int x, int y){
        int px = find(parent, x);
        int py = find(parent, y);

        if(px != py){
            parent[px] = py;
            return 1;
        }

        return 0;
    }
public:
    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();
        
        int total = n*n*4;
        vector<int>parent(total, -1);

        int count = total;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i > 0){
                    int c = unite(parent, index(n,i-1,j,2), index(n, i, j, 0));
                    count -= c;
                }
                if(j > 0){
                    int c = unite(parent, index(n,i,j-1,1), index(n, i, j, 3));
                    count -= c;
                }
                if(grid[i][j] != '/'){
                    int c = unite(parent, index(n, i, j, 0), index(n, i, j, 1));
                    count -= c;
                    c = unite(parent, index(n,i,j,2), index(n, i, j, 3));
                    count -=c;
                }
                if(grid[i][j] != '\\'){
                    int c = unite(parent, index(n, i, j, 0), index(n, i, j, 3));
                    count -= c;
                    c = unite(parent, index(n,i,j,2), index(n, i, j, 1));
                    count -=c;
                }


            }
        }
        return count;
        
    }
};