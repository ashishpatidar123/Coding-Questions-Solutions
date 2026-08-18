class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length();

        int start = 0;
        int end = n-1;

        while(end>start){
            
            char c1 = s[start];
            char c2 = s[end];
            if(((c1>= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <='Z') || (c1 >= '0' && c1<= '9')) && 
                ((c2>= 'a' && c2 <= 'z') || (c2 >= 'A' && c2 <='Z') || (c2 >= '0' && c2 <= '9'))){

                if(tolower(c1) != tolower(c2)){
                    return false;
                }
                else{
                    start++;
                    end--;
                }
            }
            if((c1 < 'a'  || c1 >'z') && (c1 < 'A' || c1 > 'Z') && (c1 < '0' || c1 > '9')){
                start++;
            }
            if((c2 < 'a' || c2 >'z') && (c2 < 'A' || c2 > 'Z') && (c2 < '0' || c2 > '9')){
                end--;
            }

        }
        return true;

    }
};
