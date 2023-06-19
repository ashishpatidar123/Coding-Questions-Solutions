class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
	    // vector to store the indegree of all the nodes
	    vector<int> indegree(V);
	    // store the indegree
	    for(int i=0; i<V; i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    // create a queue to perfomr bfs
	    queue<int> q;
	    // first push all those nodes to queue whose indgree is 0
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    // perform bfs
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        // add to our ans
	        ans.push_back(front);
	        // traverse for the neighbours
	        for(auto i:adj[front]){
	            // decrease their indegree
	            indegree[i]--;
	            // of indegree is 0 then push into the queue
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    // return ans
	    return ans;
	}
};
