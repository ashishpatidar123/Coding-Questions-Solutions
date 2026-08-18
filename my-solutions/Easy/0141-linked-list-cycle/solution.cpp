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
    bool hasCycle(ListNode *head) {
        // check for empty list
        // if it is empty then return true
        if(head==NULL){
            return false;
        }
        // create a map which stores true if a node was already visited
        map<ListNode*,bool> visited;

        // traversing the linked list and for each node checking if it's value in the map
        // is true or not. If it's true then that particular node is visited twice
        // which means a loop is present 
        // else return false
        ListNode*temp = head;
        while(temp!=NULL){
            if(visited[temp] == true){
                return true;
            }
            // mark true if the node is not visited earlier
            visited[temp] = true;
            temp = temp->next;
        } 
        return false; //loop is not present
    }
};
