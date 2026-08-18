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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        // finding pivot
        while(curr!=NULL && curr->val!=x){
            curr = curr->next;
        }
        ListNode* pivot = curr;
        // first adding all the smaller elements
        curr = head;
        while(curr!=NULL){
            if(curr->val < x){
                ListNode* temp2 = new ListNode(curr->val);
                temp->next = temp2;
                temp = temp2;
            }
            curr = curr->next;
        }
        // now adding all the greater elements which are before the pivot
        curr = head;
        while(curr!=pivot){
            if(curr->val>x){
                ListNode* temp2 = new ListNode(curr->val);
                temp->next = temp2;
                temp = temp2;
            }
            curr = curr->next;
        }
        // adding elements which are greater than or equal to pivot and are in the right side of the pivot
        curr = pivot;
        while(curr!=NULL){
            if(curr->val>=x){
                ListNode* temp2 = new ListNode(curr->val);
                temp->next = temp2;
                temp = temp2;
            }
            curr = curr->next;
        }
        return dummy->next;

    }
};
