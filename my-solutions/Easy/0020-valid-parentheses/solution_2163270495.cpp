class Solution {
    bool check(char open, char close){
        if(open == '(' && close == ')') return true;
        else if(open == '[' && close == ']') return true;
        else if(open == '{' && close == '}') return true;
        return false;
    }
public:
    bool isValid(string s) {

        int n = s.size();
        stack<char>st;

        int i = 0;

        while( i < n){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    char c = st.top();
                    if(check(c, s[i])){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            i++;
            
        }
        if(!st.empty()){
            return false;
        }
        return true;
        
    }
};