class Solution {
  private:
    void vertical(Node* root, int row, int col, map<pair<int,int>,vector<int>> &store){
        if(root==NULL){
            return;
        }
        store[{col,row}].push_back(root->data);
        vertical(root->left,row+1,col-1,store);
        vertical(root->right,row+1,col+1,store);
    }
  public:
    vector <int> bottomView(Node *root) {
        
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        int row = 0;
        int col = 0;
        map<pair<int,int>,vector<int>> store;
        vertical(root,row,col,store);
        map<int,vector<int>> temp;
        for(auto i:store){
            
            // sort(i.second.begin(),i.second.end()); 
           // now we want to insert this element to its correponding column
          for(int j=0; j<i.second.size(); j++){
               temp[i.first.first].push_back(i.second[j]);
          } 
              
        }
        
        for(auto i:temp){
            // add only the rightmost element to answer 
            // since the bottom layer is added to temp in the last so we can directly add 
            // its last element to our ans
            ans.push_back(i.second[i.second.size()-1]);
            
        }
        return ans; 
    }
