class Solution {
    bool check(char ch1, char ch2){
        // comparing the two brackets if they form a pair then return true 
        // else return false
        if(ch1=='(' && ch2==')' || ch1=='{' && ch2=='}' || ch1=='[' && ch2==']'){
            return true;
        }
        else {
            return false;
        }

    }
public:
    bool isValid(string s) {
        // create a stack
        stack<char> temp;
        // find the length of the string
        int n = s.length();
        int i =0;
        // traverse through the string
        while(n>0){
            // check if the stack is empty or not
            if(temp.empty()){
                // if it is empty then push the bracket inside the stack
                temp.push(s[i]);
            }
            // else check for the upcoming bracket 
            // if it is a closed bracket then
            else if(s[i] == ')' || s[i]== '}' || s[i] == ']'){
                // compare the topmost bracket inside the stack 
                // with this upcoming bracket
                char ch1 = temp.top();
                char ch2 = s[i];
                if(check(ch1,ch2)){
                    // if it matches with the corresponding open bracket then pop out the 
                    //top open bracket
                    temp.pop();
                }
                // else return false 
                // which means the top bracket is either a closed bracket or a 
                // non matching open bracket
                else{
                    return false;
                }
            }
            // if the upcoming bracket is a open bracket then push it inside the stack
            else {
                temp.push(s[i]);
            }
            // update the counters
            n--;
            i++;
        }
        // now check if at then end we find our stack as empty then return true
        if(temp.empty()){
            return true;
        }
        // else return false
        return false;
        
    }
};
