class Solution {
private: 
    bool isValid(vector<vector<int>>&image, int i, int j, int n,int m, int current_color){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==current_color){
            return true;
        }
        else{
            return false;
        }
    }
    void dfs(vector<vector<int>>& image, int i, int j, int n,int m,int color, int current_color){

        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==current_color){
            image[i][j] = color;
        }
        if(isValid(image,i+1,j,n,m,current_color)){
            dfs(image,i+1,j,n,m,color,current_color);
        }
        if(isValid(image,i,j+1,n,m,current_color)){
            dfs(image,i,j+1,n,m,color,current_color);
        }
        if(isValid(image,i-1,j,n,m,current_color)){
            dfs(image,i-1,j,n,m,color,current_color);
        }
        if(isValid(image,i,j-1,n,m,current_color)){
            dfs(image,i,j-1,n,m,color,current_color);
        } 
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int current_color = image[sr][sc];

        if(current_color!=color){
            dfs(image,sr,sc,n,m,color,current_color);
        }
        
        return image;
    }
};
