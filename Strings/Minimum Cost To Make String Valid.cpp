#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    
    // if the string is of odd length
    // which means we cannot make pairs 
    // return -1 in this case
    if(str.length()%2==1){
      return -1;
    }
    // declare stack s
    stack<char> s;
    // traverse the string
    for(int i=0; i<str.length(); i++){
      // store the character
      char ch = str[i];
      // if the chatacter is a open bracket then push it in the stack
      if(ch == '{'){
        s.push(ch);
      }
      // else if the character is a closing bracket
      else{
        // check for the empty condition and if it is not empty
        // then check if the topmost element is a opening bracket or not?
        // if it is a opening bracket then we found a valid pair of 
        // brackets. So pop out the top opening bracket
        if(!s.empty() && s.top() == '{'){
          s.pop();
        } 
        // else if the stack is empty or the topmost bracket is not 
        // a opening bracket then push the character into the stack
        else{
          s.push(ch);
        }
      }
    }
    // now in the stack only the invalid pair of brackets are there
    // declare a and b as the number of opening and closing brackets 
    // respectively
    int a = 0;
    int b = 0;
    // count a and b
    while(!s.empty()){
      if(s.top() == '{'){
        s.pop();
        a++;
      }
      else{
        s.pop();
        b++;
      }
    }
    // we can easily find that possible invalid expressions are:
    // 1) either we can have all the opening brackets {{{
    // 2) or we can have all the closing brackets }}}}
    // 3) or we can have both opening and closing brackets but in
    // wrong order }}}{{{
    // for minimum cost we can easily find a pattern
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
  
}
