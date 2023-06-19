#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
       
        unordered_map<int,list<int>> adj;

        void addEdge(int u, int v, bool direction){
            // direction = 0 mtlb undirected graph
            // direction = 1 mtlb directed graph
            
            // create an edge from u to v
            adj[u].push_back(v);
            // if undirected then add edge from v to u also
            if(direction==false){
                adj[v].push_back(u);
            }

        }

        void printadjList(){
            for(auto i: adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }
};
int main(){
    int n = 0;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m=0;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u;
        int v;
        cin>>u;
        cin>>v;

        g.addEdge(u,v,0);
    }
    g.printadjList();
    return 0;
}
