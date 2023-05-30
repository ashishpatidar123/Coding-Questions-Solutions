/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* swap(ListNode* next1, ListNode* next2){
    // making the pointer of the first node to point to third node
    next1->next = next2->next;
    // making the pointer of the second node to point to first node instead of third node
    next2->next = next1;
    // return the second node which actually become first node after swapping
    return next2;
}
ListNode* Solution::swapPairs(ListNode* head) {
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    // create a dummy start node
    ListNode* start = new ListNode(0);
    // add it in the beginning of the list
    start->next = head;
    // start from the dummy node
    ListNode* curr = start;
    // traverse till the last two nodes are not reached
    while(curr->next!=NULL && curr->next->next!=NULL){
        // make the pointer of the current node to point to the swapped node pair
        curr->next = swap(curr->next, curr->next->next);
        // update the current node such that it jumps by two steps 
        // as both the next node are already swapped
        curr = curr->next->next;
    }
    // return the head or start->next
    return start->next;
    
    
}
