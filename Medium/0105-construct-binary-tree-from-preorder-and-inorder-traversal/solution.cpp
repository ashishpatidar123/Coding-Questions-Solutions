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
    TreeNode* func2(vector<int>&preorder, vector<int>&inorder, int &pre, unordered_map<int,int>&m, int start, int end){

            if(start>end) return NULL;

            int val = preorder[pre];
            pre++;

            TreeNode* root = new TreeNode(val);
            int index = m[val];

            root->left = func2(preorder, inorder, pre, m, start, index-1);
            root->right = func2(preorder, inorder, pre, m , index+1, end);
            return root;

    }
    TreeNode* func1(vector<int>& preorder, vector<int>& inorder, int &size){

        unordered_map<int,int>m;
        for(int i=0; i<size; i++){
            int t = inorder[i];
            m[t] = i;
        }
        int pre = 0;
        int start = 0;
        int end = size-1;
        return func2(preorder, inorder, pre, m, start, end );

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int size = sizeof(preorder)/sizeof(preorder[0]);
        size = inorder.size();
        if(size==0) return NULL;
        TreeNode* root = func1(preorder, inorder, size);

        return root;
    }
};
