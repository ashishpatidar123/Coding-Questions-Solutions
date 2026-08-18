class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();

        stack<char>st;

        int i = 0;

        while(i<n){

            char c = s[i];

            if(!st.empty()){
                char t = st.top();

                if(c == ')' && t == '('){
                    st.pop();
                }
                else if(c == '}' && t == '{'){
                    st.pop();
                }
                else if(c == ']' && t == '['){
                    st.pop();
                }
                else if( c == '(' || c == '[' || c == '{'){
                    st.push(c);
                }
                else{
                    return false;
                }
            }
            else{
                st.push(c);
            }
            i++;

        }
        if(!st.empty()) return false;
        return true;
    }
};
