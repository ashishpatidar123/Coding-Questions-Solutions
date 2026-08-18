ListNode* Solution::detectCycle(ListNode* A) {
    
    if(A==NULL){
        return NULL;
    }
    if(A->next ==  NULL){
        return A;
    }
    // create two pointers slow and fast
    ListNode * slow = A;
    ListNode * fast = A;
    bool check = false;
    // traverse the list untill either of them become null
    while(slow!=NULL && fast!=NULL){
        // increase fast by two steps
        fast = fast->next;
        if(fast!=NULL && fast->next!=NULL){
            fast = fast->next;
        }
        // increase slow by one step
        slow = slow->next;
        // if both become equal then we find a loop
        // break at this point
        if(slow==fast){
            check = true;
            break;
        }
    }
    // if we didn't found a loop then return null
    if(check == false){
        return NULL;
    }
    // declare the above loop node as temp
    ListNode* temp = slow;
    slow = A;
    // traverse until slow become equal to temp
    while(slow!=temp){
        // increment both by one
        slow = slow->next;
        temp = temp->next;
    }
    // return either of the pointer as they become equal
    return slow;
    
}
