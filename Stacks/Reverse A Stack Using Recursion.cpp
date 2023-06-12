class Solution{
    void insert(stack<int> &St, int x){
        if(St.empty()){
            St.push(x);
            return;
        }
        int num = St.top();
        St.pop();
        
        insert(St,x);
        St.push(num);
    }
public:
    void Reverse(stack<int> &St){
        
        
        if(St.empty()){
            return;
        }
        // store the topmost element before popping out
        int num = St.top();
        St.pop();
        // reverse the stack
        Reverse(St);
        // now store the topmost element at the bottom
        insert(St,num);
        
        
    }
};
