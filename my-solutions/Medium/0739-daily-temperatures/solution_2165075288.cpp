class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);
        for (int i = 0; i < n; i++) {
            int curr = temperatures[i];

            while (!st.empty() && temperatures[st.top()] < curr) {
                int idx = st.top();
                st.pop();

                ans[idx] = i-idx; 
            } 

            st.push(i);
        }

        return ans;
        
    }
};