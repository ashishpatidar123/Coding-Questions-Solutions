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
private:
    bool findValue(TreeNode* root, int value) {
        if (root == NULL)
            return false;

        if (root->val == value)
            return true;
        else if (root->val > value)
            return findValue(root->left, value);
        else
            return findValue(root->right, value);
    }
    bool solve(TreeNode*root,int target, TreeNode*current, bool& found) {
        if (current == NULL)
            return false;

        int complement = target - current->val;

        if (complement != current->val && findValue(root, complement))
            found = true;

        solve(root, target, current->left, found);
        solve(root, target, current->right, found);

        return found;
    }   
public:
    bool findTarget(TreeNode* root, int k) {
        bool found = false;
        return solve(root,k,root,found);
    }
};
