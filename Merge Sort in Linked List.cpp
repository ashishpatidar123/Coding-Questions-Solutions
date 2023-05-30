Node* getMiddle(Node* head){
    // declare fast and slow pointers to find the middle of the list
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        // if(fast->next!=NULL){
        //     fast = fast->next;
        // }
        slow = slow->next;
    }
    return slow;
}
Node* merge(Node* left, Node* right){
    // check if there is only half
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    // create a dummy node to add nodes to it
    Node* ans = new Node(-1);
    Node* temp = ans;
    // traverse untill we reaches end of either of the list
    while(left!=NULL && right!=NULL){
        // check for the values 
        // if right node value is greater than the left node 
        // then add right node to the dummy node list
        if(left->data > right->data){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        // else add left node
        else{
            temp->next = left;
            temp = left;
            left = left->next;
        }
    }
    // now check if nodes are left in left half 
    // if yes then add those nodes to the dummy list
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    // same for right half
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    // now our final answer list is obtained by deleting the dummy node
    // so we just return the pointer to the node after the dummy node
    ans = ans->next;
    return ans;

}
Node *sortLL(Node *head){
    // check for empty and single node list
    if(head==NULL || head->next==NULL){
        return head;
    }
    // get the pointer to the middle node
    Node* middle = getMiddle(head);
    // declare the pointer to the left half
    Node* left = head;
    // declare the pointer to the right half starting from the node next to
    // the middle
    Node* right = middle->next;
    // break the two list
    middle->next = NULL;
    // from here we get pointers to the sorted left half and sorted right half
    left = sortLL(left);
    right = sortLL(right);
    // merge two sorted halves
    Node* result = merge(left,right);

    return result;

    
}
