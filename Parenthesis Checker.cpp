class Solution
{   private:  
    // function to check for the same type of open and closed bracket
    bool issame(char a , char b){
        if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}'){
            return true;
        }
        else return false;
    }
    // function to check for an open bracket
    bool isopen(char a){
        if(a == '[' || a == '{' || a == '('){
            return true;
        }
        else return false;
    }
    // function to check for a closed bracket
    bool isclose(char a){
        if(a == ']' || a == '}' || a == ')'){
            return true;
        }
        else return false;
    }
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {   
        // declare a stack
        stack<char> st;
        
        // traverse the string
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            // check is the stack is empty and the ch is a closed bracket
            // if it is true then return false because we're getting a closed bracket first
            if(st.empty() && isclose(ch)){
                return false;
            }
            
            //check for the empty stack and push ch into the stack
            else if(st.empty()){
                st.push(ch);
            }
            
            // if ch is an open bracket then push into the stack
            else if(isopen(ch)){
                st.push(ch);
            }
            
            // if ch is a close bracket
            else if(isclose(ch)){
                
                // check for the empty condition and if the stack is not empty then
                // check is we get then correponding open bracket at top or not
                // if yes then pop out of the stack
                if(!st.empty() && issame(st.top(),ch)){
                    st.pop();
                }
                
                // else check for the empty condition and for the open bracket at the top
                // if we find an open bracket at the top then return false 
                // because it's always a non matching bracket 
                // since we already checked for the matching open bracket above
                else if(!st.empty() && isopen(st.top())){
                    return false;
                }
                
                // else if the bracket at the top is a closed then push ch into the stack
                else if(!st.empty() && isclose(st.top())){
                    st.push(ch);
                }
                
                // if the stack is empty then return false 
                else if(st.empty()){
                    return false;
                }
            }
        }
        
        // if the stack is empty then return true 
        // because we pop out all the valid pairs
        if(st.empty()){
            return true;
        }
        // else return false
        else return false;
        
    }

};
