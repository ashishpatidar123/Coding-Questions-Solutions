class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>distance(n);
	    for(int i=0; i<n; i++){
	        distance[i]=INT_MAX;
	    }
	    distance[0]=0;
	    
	    for(int i=0; i<n-1; i++){
	        for(int j=0; j<edges.size(); j++){
	            int u = edges[j][0];
	            int v = edges[j][1];	        
	            int weight = edges[j][2];
	            
	            if(distance[u]!=INT_MAX && distance[v]>distance[u]+weight){
	                distance[v]=distance[u]+weight;
	            }
	        }
	    }
	    for(int i=0; i<edges.size(); i++){
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int weight = edges[i][2];
	        
	        if(distance[v]>distance[u]+weight){
	            return 1;
	        }
	    }
	    return 0;
	}
};
