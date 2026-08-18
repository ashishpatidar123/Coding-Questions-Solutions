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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        int len = 0;
        ListNode*temp = head;
        // finding the length of the linked list
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        //finding the kth node from the beginning;
        int count = 1;
        ListNode*temp1 = head;
        while(count<k && temp1!=NULL){
            temp1 = temp1->next;
            count++;
        }
        count = 1;
        ListNode*temp2 = head;
        //finding the kth node from the end
        // which is same as the (len-k+1)th node from the beginning
        while(count<len-k+1){
            temp2 = temp2->next;
            count++;
        }
        int data1 = temp1->val;
        temp1->val = temp2->val;
        temp2->val = data1;
        return head;
    }
};
