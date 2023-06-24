/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
        TreeNode* solve(TreeNode* root,vector<int> &temp, int n,int    
                start, int end){

            if(start>end){
                return NULL;
            }
            int mid = (end+start)/2;
            root = new TreeNode(temp[mid]);
            
            root->left = solve(root,temp,n,start,mid-1);
            root->right = solve(root,temp,n,mid+1,end);
            return root;
        }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> temp;
        ListNode* curr = head;
        
        while(curr!=NULL){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        int n = temp.size();
        int start = 0;
        int end = n-1;
        TreeNode*root = NULL;
        root = solve(root,temp,n,start,end);
        return root;
    }
};
