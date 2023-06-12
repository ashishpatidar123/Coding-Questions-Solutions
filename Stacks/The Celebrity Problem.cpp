class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // brute force approach
        // for(int i=0; i<n; i++){
        //     bool check1 = true;
        //     for(int j=0; j<n; j++){
        //         if(M[i][j]!=0){
        //             check1 = false;
        //         }
        //     }
        //     if(check1==true){
        //         bool check2 = true;
        //         for(int k =0; k<n; k++){
        //             if(i!=k && M[k][i]!=1){
        //                 check2 = false;
        //             }
        //         }
        //         if(check2==true){
        //             return i;
        //         }
        //     }
        // }
        // return -1;
        
        // O(N) approach
        // store all the people in a stack
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        // check until stack has only one person left
        // that person might be the celebrity
        while(st.size()>1){
            
            // pop out first two people
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            // check if a knows b or not
            // if a knows b then a can't be a celebrity so discard it and push b into the stack
            if(M[a][b] == 1){
                st.push(b);
            }
            //else discard b and push a because there is a chance of 'a' being a celebrity
            else{
                st.push(a);
            }
            
        }
        // now take out the last person
        int ans = st.top();
        
        // verify it 
        for(int i=0; i<n; i++){
            if(M[ans][i]!=0){
                return -1;
            }
        }
        for(int i=0; i<n; i++){
            if(ans!=i && M[i][ans]!=1){
                return -1;
            }
        }
        // return answer
        return ans;
    }
};
