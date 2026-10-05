/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL){
            return NULL;
        }
        if(node->val == p->val) return node;
        if(node->val == q->val) return node;

        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);

        if(left && right) return node;
        else if(left != NULL) return left;
        else if(right != NULL) return right;
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return dfs(root, p, q);
        
    }
};