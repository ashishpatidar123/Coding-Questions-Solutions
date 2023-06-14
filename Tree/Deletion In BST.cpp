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
    TreeNode* Min(TreeNode*root){
        
        // finding the minimum node in the tree
        // since it is BST minimum value is present at the leftmost node 
    
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if we find a null node then it means key is not present
        // in the tree
        if(root==NULL){
            return NULL;
        }
        // if we found our key then delete that node
        if(root->val == key){
            // case 1
            // if the node to be deleted is a leaf node
            // then simply delete it and return NULL
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            // case 2 
            // if the node has 1 child 
            // then return that child
            // and delete the node
            if(root->left!=NULL && root->right==NULL){
                TreeNode*temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }
            // case 3
            // if the node has both the childs then
            // replace the data of the node to be deleted with the 
            // minimum value in its right subtree
            // now delete that minimum value node 
            // by calling the function for the right subtree and that 
            // minimum value
            if(root->right!=NULL && root->left!=NULL){
                int mini = Min(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        // call for the left half if key is less than root ka data
        else if(root->val>key){
            root->left =  deleteNode(root->left,key);
            return root;
        }
        // else call for the right half
        else{
            root->right = deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};
