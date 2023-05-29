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
    ListNode* getMiddle(ListNode* head){
        // create a slow(1 step at a time) and a fast pointer(2 step at a time)
        ListNode* slow = head;
        ListNode* fast = head->next;
        // traverse the list untile the fast pointer become null or node next to fast
        // become null
        while(fast!=NULL && fast->next!=NULL){
            // update pointers
            fast = fast->next->next;
            slow = slow->next;
        }
        // return the slow pointer as it points to middle of the list
        return slow;
    }
    ListNode* reverse(ListNode* temp){
        // create prev, curr and next pointers
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next2 = NULL;
        // traverse till curr not become null
        while(curr!=NULL){
            // update the next pointer
            next2 = curr->next;
            // make next of current to points to the previous node
            curr->next = prev;
            // now make the current pointer as the previous pointer
            prev = curr;
            // and next pointer as the current pointer
            curr = next2;
            
        }
        // return the prev pointer
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        // vector<int> values;
        // if(head==NULL){
        //     return head;
        // }
        // if(head->next==NULL){
        //     return head;
        // }
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     values.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int n = values.size();
        // int start = 0;
        // int end = n-1;
        // while(start<=end){
        //     if(values[start++]!=values[end--]){
        //         return false;
        //     }
        // }
        // return true;
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        // get the middle of the list
        ListNode* middle = getMiddle(head);
        // create a pointer temp to denote the list after the middle
        ListNode*temp = middle->next;
        // reverse the list after middle starting from the temp
        // and return pointer to its first node
        middle->next = reverse(temp);
        // create pointers to the first half of the list 
        // and to the second half of the list
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        // now compare values of both the halves
        while(head2!=NULL){
            // if values doesn't match then simply return false
            if(head1->val!=head2->val){
                return false;
            }
            // else update the pointers
            head1 = head1->next;
            head2 = head2->next;
        }
        // return true
        return true;

    }
};
