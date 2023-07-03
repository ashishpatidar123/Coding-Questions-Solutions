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
    void dfs(TreeNode* root,int &count, int max){
        if(root==NULL){
            return;
        }
        if(root->val >= max){
            count++;
            max = root->val;
        }
        dfs(root->left,count,max);
        dfs(root->right,count,max);
    
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count = 0;
        
        dfs(root->left,count,root->val);
        dfs(root->right,count,root->val);
        return count+1;
    }
};
