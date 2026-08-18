/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func2(vector<int>&inorder, vector<int> &postorder, int& post, int start, int end, unordered_map<int,int>&m){

        if(start>end) return NULL;

        int val = postorder[post];
        post--;
        int index = m[val];
        TreeNode* root = new TreeNode(val);
        
        root->right = func2(inorder, postorder, post, index+1, end, m);
        root->left = func2(inorder,postorder, post, start, index-1, m);
        
        return root;
    }
    TreeNode* func1(vector<int>& inorder, vector<int> &postorder, int size){
        unordered_map<int,int>m;

        for(int i=0; i<size; i++){
            m[inorder[i]] = i;
        }

        int post = size-1;
        int start = 0;
        int end = size-1;

        return func2(inorder, postorder, post, start, end, m);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int size = inorder.size();
        if(size==0) return NULL;
        TreeNode* root = func1(inorder, postorder, size);
        return root;
    }
};
