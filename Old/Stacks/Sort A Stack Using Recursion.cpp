void insertInsorted(stack<int> &s, int num){
    
    // check if the stack if empty or the top element is smaller than the
    // element to be inserted
    if(s.empty() || !s.empty() && s.top()<num){
        // if yes then push the element
        s.push(num);
        // and return
        return;
    }
    // else store the top most element before popping out
    int n = s.top();
    s.pop();
    // call the function for the rest of the stack
    insertInsorted(s,num);
    // again push the topmost element
    s.push(n);
}
void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   // storing the topmost element before popping out
   int num = s.top();
   s.pop();
   // calling the sort function for rest of the stack
   sort();
   // insert the topmost element in a sorted manner
   insertInsorted(s,num);
}
