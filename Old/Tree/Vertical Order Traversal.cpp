class Solution {
private:
    void vertical(TreeNode*root, int row, int col, map<pair<int,int>,vector<int>> &store){
        if(root==NULL){
            return;
        }
        store[{col,row}].push_back(root->val);
        vertical(root->left,row+1,col-1,store);
        vertical(root->right,row+1,col+1,store);
        
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // create a 2d vector to return the answer
        vector<vector<int>> ans;
        // if the tree is empty then return answer
        if(root==NULL){
            return ans;
        }
        // declare row and col
        int row = 0;
        int col = 0;
        // create a map of type (pair,vector) so that for every row and col index we 
        // we can store elements to that corresponding vector
        map<pair<int,int>,vector<int>> store;
        // call our helper funtion
        vertical(root,row,col,store);
        // create another map of type(int,vector)
        // so that we can insert the elements of that particular to column to its vector
        map<int,vector<int>> temp;
        // traverse the first map
        for(auto i:store){
           // sort the given elements
           sort(i.second.begin(),i.second.end()); 
           // now we want to insert this element to its correponding column
           for(int j=0; j<i.second.size(); j++){
               temp[i.first.first].push_back(i.second[j]);
           }  
        }
        // now we have all the elements in our temp map in form of vector corresponding
        // to that column
        // add all this elements to our final answer array;
        for(auto i:temp){
           ans.push_back(i.second);
        }
        return ans;

    }
};
