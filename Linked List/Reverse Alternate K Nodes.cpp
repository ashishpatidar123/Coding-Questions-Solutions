ListNode* Solution::solve(ListNode* head, int k) {
    ListNode *root= head;
    ListNode *curr= head;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    int cnt = 0;
    //to check whether we have K nodes present or not
    ListNode* temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt<k)
        return head;
    cnt = 0;
    while(curr!= NULL and cnt<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
        cnt++;
    }
    root->next = curr; //joining the next part because for that no reverse is require
    if(!curr)
        return prev;
    int x = 0;
    ListNode* next_curr = NULL;
    while(x<k)
    {
        next_curr = curr;
        curr=curr->next;
        x++;
    }
    next_curr->next = solve(curr,k);
    return prev;  
}
