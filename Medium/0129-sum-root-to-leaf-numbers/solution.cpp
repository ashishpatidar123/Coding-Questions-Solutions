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
    
    int findsum(vector<int> path){
        int temp = 0;
        for(int i=0; i<path.size(); i++){
            temp = 10*temp + path[i];
        }
        return temp;
    }
    void solve(TreeNode *root, int &sum, vector<int> path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            sum = sum + findsum(path);
            return;
        }
        solve(root->left,sum,path);
        solve(root->right,sum,path);
    }
public:
    int sumNumbers(TreeNode* root) {
        
        vector<int> path;
        int sum = 0;
        solve(root,sum,path);
        return sum;
    }
};
