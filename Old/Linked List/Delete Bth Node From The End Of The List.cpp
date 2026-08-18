/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int B) {
    // if the list is empty then simply return head
    if(head==NULL){
        return head;
    }
    // find the length of the list
    int len = 0;
    ListNode*temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    // if B is greater than or equal to length then we have to delete the first node
    if(B>=len){
        // create a temp node which points to the second node
        ListNode* temp = head->next;
        // empty the head pointer
        head->next = NULL;
        // delete the head 
        delete(head);
        // make the temp as the new head and return head
        head = temp;
        return head;
    }
    // Bth node from the end is same as the (len-B+1)th node from the beginning
    int count = len-B+1;
    // create two pointers curr and prev
    ListNode* curr = head;
    ListNode* prev = NULL;
    // update the pointers until we reach either end of the list or at the node to be deleted
    while(count>1 && curr!=NULL){
        prev = curr;
        curr = curr->next;
        count--;
    }
    // make the prev pointer to point to the node after the current node
    // current node is the node which we want to delete
    prev->next = curr->next;
    curr->next = NULL;
    // delete the current node
    delete(curr);
    // return head
    return head;
}
