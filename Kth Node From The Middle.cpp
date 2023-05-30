/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int Solution::solve(ListNode* head, int B) {
    if(head==NULL){
        return -1;
    }
    // find the length
    int len = 0;
    ListNode* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    // find the middle
    int middle = len/2 + 1;
    // the Bth node from the middle towards the beginning is same as the (middle - B)th node from the beginning
    int begin = middle - B;
    // if begin is less than 0 or equal to 0 then we're accessing a node which is not in the list
    // so simply return -1
    if(begin<=0){
        return -1;
    }
    // start from the first node and traverse till begin is greater that one
    ListNode* curr = head;
    while(begin>1){
        curr = curr->next;
        begin--;
    }
    // return the value of the current node
    return curr->val;
}
