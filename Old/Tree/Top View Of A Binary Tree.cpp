class Solution
{
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
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
            // checking if we already had entries for that column
            if(temp.find(i.first.first)==temp.end()){
                // if not then push only the leftmost node
                for(int j=0; j<1; j++){
                    temp[i.first.first].push_back(i.second[j]);
                }
            }
              
        }
        
        for(auto i:temp){
            for(int j =0; j<i.second.size(); j++){
                ans.push_back(i.second[j]);
            }
            
        }
        return ans;
    }

};
// other comments are similar to the vertical order traversal question
