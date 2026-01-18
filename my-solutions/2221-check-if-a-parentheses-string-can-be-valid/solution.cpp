class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int n = s.length();

        int free = 0;
        int balanced = 0;
        if(n%2!=0) return false;
        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                free++;
            }
            else if(s[i] == '('){
                balanced++;
            }
            else{
                balanced--;
            }
            if(balanced+free < 0){
                return false;
            }
        }
        free = 0;
        balanced = 0;

        for(int i=n-1; i>=0; i--){
            
            if(locked[i] == '0'){
                free++;
            }
            else if(s[i] == ')'){
                balanced++;
            }
            else{
                balanced--;
            }
            if(balanced+free < 0){
                return false;
            }
        }
        return true;


    }
};
