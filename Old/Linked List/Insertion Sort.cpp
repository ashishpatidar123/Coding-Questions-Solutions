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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        // create a dummy node
        ListNode* dummy = new ListNode(INT_MIN);
        // create a current pointer
        ListNode* curr = head;
        // traverse till the end of the list
        while(curr!=NULL){
            // initialise a prev pointer starting from the dummy node
            ListNode*prev = dummy;
            // update the prev pointer until it's next node is greater than the current node
            while(prev->next!=NULL && prev->next->val<=curr->val){
                prev = prev->next;
            }
            // now we have four nodes
            // prev, prev->next, curr and curr->next

            ListNode* next = curr->next;
            // link the next of the current to the prev ka next 
            // because it's is greater than the current so should come after current in the
            // resulting list
            curr->next = prev->next;
            // now also make the curr as prev next because we had changed the pointers
            prev->next = curr;
            // now the three node
            // prev, prev->next and curr are in sorted manner
            // so move to next node
            curr = next;
        }
        return dummy->next;
    }
};
