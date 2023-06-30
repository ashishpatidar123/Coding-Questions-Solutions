class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>m;
        
        queue<Node*>q;
        q.push(node);
        Node* src = new Node(node->val);
        m[node]=src;
        
        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            vector<Node*>adj = u->neighbors;
            
            int n = adj.size();
            for(int i=0; i<n; i++){
                
                if(m[adj[i]]==NULL){
                    src = new Node(adj[i]->val);
                    m[adj[i]]=src;
                    q.push(adj[i]);
                }
                m[u]->neighbors.push_back(m[adj[i]]);
            }
        }
        return m[node];
    }
};
