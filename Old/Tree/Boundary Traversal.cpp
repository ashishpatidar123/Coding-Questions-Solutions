class Solution {
private:
    void leftBoundary(Node*root, vector<int> &ans){
        // if root is null then return
        if(root==NULL){
            return;
        }
        // if it is a leaf node then return because we will print this while printing
        // leaves
        if(root->left==NULL && root->right ==NULL){
            return;
        }
        // else print the node
        ans.push_back(root->data);
        
        // if left node is not null then call for the left subtree
        if(root->left){
            leftBoundary(root->left,ans);
        }
        // else call for the right subtree
        else{
            leftBoundary(root->right,ans);
        }
    }
    
    void printleaves(Node*root,vector<int> &ans){
        // if root is null then return
        if(root==NULL){
            return;
        }
        // if the node is a leaf node then print and return
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        // else call for the left and right subtree 
        else{
            printleaves(root->left,ans);
            printleaves(root->right,ans);
        }
    }
    
    void rightBoundary(Node*root, vector<int> &ans){
        // if root is null then return
        if(root==NULL){
            return;
        }
        // if it is a leaf node then return because we will print this node while 
        // printing leaves
        if(root->left==NULL && root->right==NULL){
            return;
        }
        // if right node is not null then move to the right subtree
        if(root->right){
            rightBoundary(root->right,ans);
        }
        // else move to the left subtree
        else{
            rightBoundary(root->left,ans);
        }
        // print the node
        // we're printing after the function calls because we want to print from 
        // bottom to up
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        // push the root node
        ans.push_back(root->data);
        
        // print the left boundary
        leftBoundary(root->left,ans);
        
        // print left subtree leaves 
        printleaves(root->left,ans);
        // print right subtree leaves
        printleaves(root->right,ans);

        // print the right boundary
        rightBoundary(root->right,ans);
        
        return ans;
    }
};
