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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp = head;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        int len = 0;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        temp = head;
        int count = 0;
        ListNode* prev1 = NULL;
        while(count<len/2){
            prev1 = temp;
            temp = temp->next;
            count++;
        }
        prev1->next = temp->next;
        temp->next = NULL;

        delete temp;
        return head;

    }
};
