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
public:
    vector<int>result;

    void findDownwards(TreeNode* node, int distance){

        if(!node || distance < 0){
            return ;
        }

        if(distance == 0){
            result.push_back(node->val);
            return;
        }

        findDownwards(node->left, distance - 1);
        findDownwards(node->right, distance -1);
    }

    int dfs(TreeNode* node, TreeNode* target, int k){

        if(!node) return -1;

        if(node == target){
            findDownwards(node, k);
            return 1;
        }

        int left_dist = dfs(node->left, target, k);

        if(left_dist != -1){
            if(left_dist == k){
                result.push_back(node->val);
            }
            else{
                findDownwards(node->right, k - left_dist - 1);
            }

            return left_dist + 1;
        }

        int right_dist = dfs(node->right, target, k);

        if(right_dist != -1){
            if(right_dist == k){
                result.push_back(node->val);
            }
            else{
                findDownwards(node->left, k-right_dist -1);
            }
            return right_dist + 1;
        }

        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        dfs(root, target, k);
        return result;
        
    }
};
