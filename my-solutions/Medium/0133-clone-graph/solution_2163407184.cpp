/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*>check;

    Node* dfs(Node* curr){
        if(check.find(curr) != check.end()){
            return check[curr];

        }
        Node* copy = new Node(curr->val);
        check[curr] = copy;

        for(Node* v : curr->neighbors){
            
            copy->neighbors.push_back(dfs(v));
            
            
        }

        return copy;

    }
public:
    Node* cloneGraph(Node* node) {

        
        Node* clone = NULL;
        if(node != NULL){
            clone = dfs(node);
        }
        
        return clone;


        
    }
};