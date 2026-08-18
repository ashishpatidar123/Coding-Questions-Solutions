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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // check for empty list
        if(head==NULL){
            return head;
        }
        // check is there is only node in the list then just return head because there 
        // won't be any duplicates
        if(head->next==NULL){
            return head;
        }
        // initialise a curr pointer to head
        ListNode*curr = head;
        // traverse through the list until the curr node is NULL
        while(curr!=NULL){
            // check for whether curr is the last node or not 
            // if it's not last then check for the value of the curr
            // and the next node
            if((curr->next!=NULL) && (curr->val==curr->next->val)){
                // if the values are equal then create a next to next node
                // and a node to be deleted
                ListNode*next_next = curr->next->next;
                ListNode*todelete = curr->next;
                // making the next of the node to be delete NULL
                todelete->next = NULL;
                // deleting the duplicate node
                delete(todelete);
                //pointing the next of the current node to the next to next node
                curr->next = next_next;

            }
            // if values are not equal then simply increase the curr pointer to 
            // the next node
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
