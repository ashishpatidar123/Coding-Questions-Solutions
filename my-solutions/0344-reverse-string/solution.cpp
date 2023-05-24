class Solution {
    void reverse(vector<char>& s, int i, int j){
        if(i>j){
            return;
        }
        swap(s[i],s[j]);
        i++;
        j--;
        return reverse(s,i,j);
    }
public:
    void reverseString(vector<char>& s) {
        // int start = 0;
        // int end = s.size()-1;

        // while(start<end){
        //     swap(s[start++],s[end--]);
        // }
        int i = 0;
        int j = s.size()-1;
        reverse(s,i,j);

    }
};
