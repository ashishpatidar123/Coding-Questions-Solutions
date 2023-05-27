/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // checking for the empty list 
        // if the list is empty simply return NULL pointer or the head pointer
        if(head==NULL){
            return head;
        }
        // creating a map which stores value true is a Node is visited
        map<ListNode*,bool> visited;

        ListNode*temp = head;
        // iterating over all the nodes and checking if the of a node in the 
        // map is true or not
        // if it's true then the node was already visited which means a loop 
        // is present and return the node 
        while(temp!=NULL){
            if(visited[temp]==true){
                return temp;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        // else return null which means no loop is present in the list
        return NULL;

    }
};
