class Solution {
public:
    string smallestString(string s) {
        int index1 = s.length();
        int index2 = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i]!='a'){
                index1 = i;
                break;
            }
        }
        if(index1==s.length()){
            s[index1-1] = 'z';
        }
        int i = index1+1;
        while(i<s.length() && s[i]!='a'){
            i++;
        }
        index2 = i-1;
        for(int i=index1; i<=index2; i++){
            s[i] = s[i]-1;
        }
        return s;
    }
};
