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
    void solve(TreeNode* root, int sum, vector<int> path, 
                vector<vector<int>> &ans){
            
            if(root==NULL){
                return;
            }
            path.push_back(root->val);
            if(root->val==sum && root->left==NULL &&                
                            root->right==NULL)   
            {
                ans.push_back(path);
            }

            solve(root->left,sum-root->val,path,ans);
            solve(root->right,sum-root->val,path,ans);

        }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,targetSum,path,ans);
        return ans;
    }
};
