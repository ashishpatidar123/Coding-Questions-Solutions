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

//Another approach

#include <bits/stdc++.h> 
void solve(stack<int>& myStack,int x){
    //check for the empty condition
    // if it is empty then push our element
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    // store the topmost element
    // because we have to push it later
    int num = myStack.top();
    // remove the topmost element
    myStack.pop();
    // recursive call after removing the topmost element
    // thus decreasing the size of the stack
    solve(myStack,x);
    // again push the top element 
    myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x){ 

       solve(myStack, x);
       return myStack;
}

