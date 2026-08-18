class Solution {
public:
    bool isPalindrome(int A) {
    vector<int> check;
    
    int i=0;
    if(A<0){
        return false;
    }
    if(A==0){
        return true;
    }
    while(A>0){
        check.push_back(A%10);
        A = A/10;
        i++;
    }
    if(check.empty()){
        return false;
    }
    int start = 0;
    int end = check.size()-1;
    
    while(start<end){
        if(check[start++]!=check[end--]){
            return false;
        }
    }
    return true;
    }
};
