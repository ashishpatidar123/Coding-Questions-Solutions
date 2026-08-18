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
private:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        // finding the length of the list
        int n = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            curr = curr->next;
            n++;
        }
        // find middle
        if(n%2==0){
            n = n/2;
        }
        else{
            n = (n+1)/2;
        }
        // finding the middle node
        ListNode* newHead = new ListNode(-1);
        curr = head;
        ListNode* prev = NULL;
        while(n>0){
            prev = curr;
            curr = curr->next;
            n--;
        }
        // break the list from the middle
        prev->next = NULL;
        newHead = curr;
        // reverse the list after the middle
        newHead = reverse(newHead);
        // now we have two lists 
        // first -  the list till middle
        // second - the reversed list after middle
        ListNode* first = head;
        ListNode* second = newHead;
        // create a dummy node and add nodes as given in the question
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        bool flag = true;
        while(first!=NULL || second!=NULL){
            if(flag){
                temp->next = first;
                temp = first;
                first = first->next;
            }
            else{
                temp->next = second;
                temp = second;
                second = second->next;
            }
            flag = !flag;
        }
        head = dummy->next;
    }
};
