class Solution {
    int precedence(char a){
        // defining the precedence
        switch(a){
            case '+':
            case '-':
                return 1;
            
            case '*':
            case '/':
                return 2;
            
            case '^':
                return 3;
            
            default:
               return -1;
        }
    }
    bool isoperator(char ch){
        // checking whether the character is an operator or not
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            return true;
        }
        else return false;
    }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        
        // declare an empty answer string
        string ans = "";
        
        // declare a stack
        stack<char> st;
        
        // traverse the string
        for(int i=0; i<s.length(); i++){
            
            // store the string element into a character variable
            char ch = s[i];
            
            // check if we get a space or a tab then continue to the next iteration
            if(ch == ' ' || ch == '\t'){
                continue;
            }
            
            // check for numbers and alphabets
            // if the character is a operand then add it to out answer string
            else if(isalnum(ch)){
                ans = ans + ch;
            }
            
            // if the character is an open bracket then push it into the stack
            else if(ch == '('){
                st.push(ch);
            }
            
            // if the charcater is a closed bracket then
            else if(ch == ')'){
                
                // pop out all the characters from the stack until we get an open bracket 
                // or we find the stack empty
                while(!st.empty() && st.top()!='('){
                    ans = ans + st.top();
                    st.pop();
                }
                
                // if the stack is empty then just return invalid because there is no 
                // any open bracket corresponding to our closed bracket
                if(st.empty()){
                    return "invalid";
                }
                
                // else if we find the open bracket then pop it out of the stack
                else{
                    st.pop();
                }
            }
            
            // if the character is an operator 
            else if(isoperator(ch)){
                
                // then if ch has higher precedence than the operator at the top of the stack
                // the push the ch into the stack
                if(!st.empty() && precedence(ch)>precedence(st.top())){
                    st.push(ch);
                }
                
                // else if it has a lower precedence then 
                else if(!st.empty() && precedence(ch)<=precedence(st.top())){
                    
                    // pop out the characters from the stack and add to the answer
                    // string until the stack is empty of we find an operator with lower
                    // precedence
                    while(!st.empty() && precedence(ch)<=precedence(st.top())){
                        ans = ans + st.top();
                        st.pop();
                    }
                    // push the ch
                    st.push(ch);
                }
                
                // else if the stack is empty then push ch
                else{
                    st.push(ch);
                }
                
                
            }
        }
        
        // pop out all the remaining characters from the stack and add to the answer string 
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        
        // return the answer string
        return ans;
    }
};
