#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // creating adjacency list
    unordered_map<int,vector<pair<int,int>>> adj;

    for(int i=0; i<edges; i++){

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }
    // create a set so that we can easily find the minimum distance node
    set<pair<int,int>> st;
    vector<int> distance(vertices,INT_MAX);
    // set distance of source as 0 and for other nodes as INT_MAX
    distance[source]=0;
    // insert the source node and it's distance pair into the set
    // pair of type int,int where first entry is distance of the node 
    // and the second entry is the node
    st.insert(make_pair(0,source));
    
    // run the loop until the stack is empty
    while(!st.empty()){
        
        // find the top element or the first element
        // since we're using a set so we get minimum of all the elements
        auto top = *st.begin();
        // remove this from the set
        st.erase(st.begin());
        
        // look out for it's neighbours
        for(auto i:adj[top.second]){
            int temp = top.first + i.second;
            // if the new distance is less than the old distance then update it
            if(temp<distance[i.first]){
                auto record = st.find(make_pair(distance[i.first],i.first));
                
                // first delete the pair from the stack with the old distance
                if(record!=st.end()){
                    st.erase(record);
                }

                distance[i.first] = temp;
                // insert the updated distance pair
                st.insert(make_pair(distance[i.first],i.first));

            }
        }

    }
    // return the distance array
    return distance;
}

