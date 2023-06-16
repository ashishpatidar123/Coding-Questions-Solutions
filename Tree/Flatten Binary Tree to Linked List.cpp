class Solution {
private:
    void preorder(TreeNode* root,vector<int> &store){
        if(root==NULL){
            return;
        }
        store.push_back(root->val);
        preorder(root->left,store);
        preorder(root->right,store);
    }
    void makeList(vector<int> &store,TreeNode*root)
    {
        TreeNode* curr = root;
        if(root==NULL){
            return;
        }
        root->left = NULL;
        for(int i=1; i<store.size(); i++){
            TreeNode* temp = new TreeNode(store[i]);
            curr->right = temp;
            curr->left = NULL;
            curr = temp;
        }
    }
public:
    void flatten(TreeNode* root) {
        vector<int> store;
        preorder(root,store);
        makeList(store,root);
    }
};
