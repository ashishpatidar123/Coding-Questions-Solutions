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
    bool dfs(TreeNode* node, long long mini, long long maxi){
        if(node == NULL) return true;
        if(node->val <= mini || node->val >= maxi){
            return false;
        }
        
        bool check1 = dfs(node->left, mini, node->val);

        bool check2 = dfs(node->right, node->val, maxi);

        return check1 && check2;
    }
public:
    bool isValidBST(TreeNode* root) {

        return dfs(root, LLONG_MIN, LLONG_MAX);
        
    }
};