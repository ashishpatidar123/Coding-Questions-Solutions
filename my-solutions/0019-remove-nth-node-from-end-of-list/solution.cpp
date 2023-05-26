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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next == NULL){
            delete head;
            return NULL;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        temp = head;
        int count = 0;
        ListNode* prev = NULL;
        if(n==len){
            head = temp->next;
            temp->next = NULL;
            delete temp;
            return head;

        }
        while(count<len-n){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
        
    }
};
