class Solution
{   private:
    void insertatTail(Node* &head, Node* &tail,int data){
        //insert a node at the end of the list
        Node* newnode = new Node(data);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    public:
    Node *copyList(Node *head)
    {   
        // declare two pointer head and tail to the clone list
        Node*cloneHead = NULL;
        Node*cloneTail = NULL;
        
        Node*temp = head;
        // traverse the original list and copy each node to the clone list
        while(temp!=NULL){
            insertatTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        // create an unordered map which store the mapping of a node in the original list
        // to the corresponding node in the clone list
        unordered_map<Node* , Node*> Originaltonew;
        // declare two pointers original and clonenode to traverse original and clone list
        // respectively
        Node* original = head;
        Node* clonenode = cloneHead;
        // traverse the original list and create a mapping
        while(original!=NULL){
            Originaltonew[original] = clonenode;
            original = original->next;
            clonenode = clonenode->next;
        }
        // intialise the pointers to the original and clone list to their respective heads
        clonenode = cloneHead;
        original = head;
        // traverse the clone list
        while(clonenode!=NULL){
            // make the random pointer of a node of the clone list to point to the node which
            // which is pointed by the random pointer of the corresponding mapped node of 
            // the original list
            clonenode->arb = Originaltonew[original->arb];
            //update both the pointers
            clonenode = clonenode->next;
            original = original->next;
        }
        // return head of the clone list
        return cloneHead;
    }

};
