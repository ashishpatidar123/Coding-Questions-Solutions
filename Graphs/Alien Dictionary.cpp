class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        
        // so the logic is processing each adjacent strings and if they differ at some index it
        // it means the character in the first string appears before the character in the
        // second string in the dictionary
        // so a directed edge can be formed from the character in the first string to the
        // character in the second string
        
        // we will do this for all adjacent pairs
        // now we get a directed graph
        // now we can find the topological sort
        
        
        vector<int>nodes(k,0);
        vector<vector<int>>edges(k);
        for(int i=0; i<n-1; i++){
            
            int j=0;
            int t=0;
            
            while(j<dict[i].size() && t<dict[i+1].size()){
                
                if(dict[i][j]!=dict[i+1][t]){
                    edges[dict[i][j]-'a'].push_back(dict[i+1][t]-'a');
                    break;
                }
                j++;
                t++;
                
            }
            
        }
        
        string ans="";
        
        vector<int>indegree(k);
        
        for(int i=0; i<k; i++){
            for(auto j:edges[i]){
                indegree[j]++;
            }
            
        }
        queue<int>q;
        
        for(int i=0; i<k; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            ans += u+'a';
            
            for(auto v:edges[u]){
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        
        return ans;
        
    }
};
