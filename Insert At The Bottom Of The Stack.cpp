#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{   // create an empty stack
    stack<int> temp;
    // push all the elements of the original stack to 
    // our temporary stack
    while(!myStack.empty()){
        int y = myStack.top();
        temp.push(y);
        myStack.pop();
    }
    // now our original stack is empty 
    // so push x
    myStack.push(x);
    // again push the elements in our empty stack from our
    // temporary stack
    while(!temp.empty()){
        int y = temp.top();
        myStack.push(y);
        temp.pop();
    }
    // return our original stack
    return myStack;
}
