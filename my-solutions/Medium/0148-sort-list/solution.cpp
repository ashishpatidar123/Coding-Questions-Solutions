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
    ListNode* getMiddle(ListNode*head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
    }
    ListNode* merge(ListNode*left,ListNode*right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left!=NULL && right!=NULL){
            if(left->val > right->val){
                temp->next = right;
                temp = right;
                right = right->next;
            }
            else{
                temp->next = left;
                temp = left;
                left = left->next;
            }
        }
        while(left!=NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right!=NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        dummy = dummy->next;
        return dummy;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = getMiddle(head);
        
        ListNode* left = head;
        ListNode* right = middle->next;

        middle->next=NULL;
        left = sortList(left);
        right = sortList(right);

        ListNode* result = merge(left,right);
        return result;
    }
};
