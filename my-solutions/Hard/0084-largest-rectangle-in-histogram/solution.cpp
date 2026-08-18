class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        
        //create two vectors for storing index of the nearest smaller element to the 
        // left and right of every element
        int n = A.size();
        vector<int>leftsmall;
        vector<int>rightsmall;
        
        stack<int> st;
        // finding left small
        // for the explanation look the code for the nearest smaller number problem
        leftsmall.push_back(-1);
        st.push(0);
        
        for(int i=1; i<n; i++){
            if(st.empty()){
                st.push(i);
                leftsmall.push_back(-1);
            }
            while(!st.empty() && A[st.top()]>=A[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                leftsmall.push_back(-1);
            }
            else{
                leftsmall.push_back(st.top());
                st.push(i);
            }
            
        }
        while(!st.empty()){
            st.pop();
        }
        //right small
        // for the explanation look out the code for the help classmates problem
        rightsmall.push_back(n);
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--){
            if(st.empty()){
                st.push(i);
                rightsmall.push_back(n);
            }
            while(!st.empty() && A[st.top()]>=A[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                rightsmall.push_back(n);
            }
            else{
                rightsmall.push_back(st.top());
                st.push(i);
            }
            
        }
        reverse(rightsmall.begin(),rightsmall.end());

        int max = 0;
        int area = 0;
         // now finding area by just multiplying the height with the range over which 
         // we can move either side of the element without getting a smaller element than
         // the given element
        for(int i=0; i<n; i++){
            area = A[i]*(rightsmall[i]-leftsmall[i]-1);
            if(area>max){
                max = area;
            }
            
        }
        return max;
        
    }
};
