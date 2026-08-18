/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // if the tree is empty then return null
        if(root==NULL){
            return NULL;
        }
        // start from the root node
        Node* curr = root;
        // since the tree is a perfect binary tree 
        // so we can easily check if the next level exist or not by simply checking 
        // the current nodes left pointer if it's null it means no more levels are
        // present in the tree
        while(curr->left!=NULL){
            // start from the current node of the level
            // i.e. the first node of the level
            // and traverse all the nodes of that level
            Node* temp = curr;
            while(temp!=NULL){
                // add the next pointers 
                temp->left->next = temp->right;
                if(temp->next!=NULL){
                    temp->right->next = temp->next->left;
                }
                // if we reach at the end of the level then make it's pointer NULL
                else{
                    temp->right->next = NULL;
                }
                // move to the next node
                temp = temp->next;
            }
            // move to the next levele
            curr = curr->left;
        }
        return root;
    }
};
