#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{   
    // create a stack
    stack<int> st;
    // traverse the string
    for(int i=0; i<s.length(); i++){
        // store the character
        char ch = s[i];
        // check if the chacter is an operator or a opening bracket
        // if yes then simply push it in the stack
        if(ch == '(' || ch == '+' || ch == '-'
                   || ch == '*' || ch == '/'){
            st.push(ch);
        }
        
        else{
            // if the character is a closing bracket
            if(ch==')'){
                // declare a check variable
                // which is initially true which means assuming 
                // redundant
                bool check = true;
                // check in the stack until we find a opening bracket
                while(st.top()!='('){
                    char top = st.top();
                    // if the top element is a operator
                    // mark check as false 
                    // which means we're not getting any pair of brackets
                    // without a operator inside them
                    if(top=='+'||top=='-'||top=='*'
                                || top == '/'){
                        check = false;
                    }
                    // pop out the top element
                    st.pop();
                }
                // now if our check is still true 
                // which means we found a pair of brackets without any 
                // operator inside them
                // return true 
                if(check==true){
                    return true;
                }
                // pop out the opening bracket found
                st.pop();
            }
        }
        
    }
    return false;
}
