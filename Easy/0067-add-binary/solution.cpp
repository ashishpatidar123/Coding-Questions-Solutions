class Solution {
public:
    string addBinary(string a, string b) {
        
        char carry = '0';

        int n = a.length();
        int m = b.length();
        int i = n-1;
        int j = m-1;

        string s = "";

        while(i>=0 && j>=0){

            if(a[i]=='0' && b[j] == '0'){

                if(carry=='0'){
                    s = s + '0';
                }
                else if(carry=='1'){
                    s = s + '1';
                    carry = '0';
                }
            }
            else if(a[i]=='0' && b[j] == '1'){

                if(carry=='0'){
                    s = s + '1';
                }
                else if(carry=='1'){
                    s = s + '0';
                    carry = '1';
                } 
            }
            else if(a[i]=='1' && b[j] == '0'){

                if(carry=='0'){
                    s = s + '1';
                }
                else if(carry=='1'){
                    s = s + '0';
                    carry = '1';
                }    
            }
            else {

                if(carry=='0'){
                    s = s + '0';
                    carry = '1';
                }
                else if(carry=='1'){
                    s = s + '1';
                    carry = '1';
                } 
            }
            i--;
            j--;

        }
        while(i>=0){
            if(a[i]=='0'){
                
                if(carry == '0'){
                    s = s + '0';
                    carry = '0';
                }
                else{
                    s = s + '1';
                    carry = '0';
                }
            }
            else{

                if(carry == '0'){
                    s = s + '1';
                    carry = '0';
                }
                else{
                    s = s + '0';
                    carry = '1';
                }
            }
            i--;
        }
        while(j>=0)
        {
            if(b[j]=='0'){
                
                if(carry == '0'){
                    s = s + '0';
                    carry = '0';
                }
                else{
                    s = s + '1';
                    carry = '0';
                }
            }
            else{

                if(carry == '0'){
                    s = s + '1';
                    carry = '0';
                }
                else{
                    s = s + '0';
                    carry = '1';
                }
            }
            j--;
        }
        if(carry == '1'){
            s = s + '1';
        }
        reverse(s.begin(),s.end());
        return s;

    }
};
