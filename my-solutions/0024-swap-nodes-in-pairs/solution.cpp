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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL){
            return head;
        }
        int nodes = 0;
        ListNode*temp = head;
        while(temp!=NULL){
            temp = temp->next;
            nodes++;
        }
        ListNode*prev = NULL;
        ListNode*forward = NULL;
        ListNode*curr = head;

        if(nodes>=2){
            int count = 0;
            while(count<2 && curr!=NULL){
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
            

            if(forward!=NULL){
                head->next = swapPairs(forward);
            }
        }
        else{
            return head;
        }
        return prev;
        
    }
};
