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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        queue<TreeNode* >q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
        
            int size = q.size();
            vector<int>s;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node!=NULL){
                    s.push_back(node->val);
                    if(node->left!=NULL){
                    q.push(node->left);
                    }
                    if(node->right!=NULL){
                        q.push(node->right);
                    }
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
