class Solution {
public:
    int strStr(string haystack, string needle) {
        // if length of both haystack and needle are equal then just compare the strings
        // if they are equal then return index 0
        // else return -1
        if(haystack.length()==needle.length()){
            if(haystack==needle){
                return 0;
            }
            else{
                return -1;
            }
        }
        // if length of the needle is greater than the length of the haystack
        // return -1 because it is impossible to fina needle in the haystack
        if(haystack.length()<needle.length()){
            return -1;
        }
        // traverse through the haystack
        for(int i=0; i<haystack.length()-needle.length()+1; i++){
            // declare a check variable
            bool check = true;
            // now for each index of haystack check if the next characters are forming
            // the string needle or not
            for(int j=i; j<needle.length()+i; j++){
                // if we get a nonmatching character then mark check as false and break
                // the loop
                if(haystack[j]!=needle[j-i]){
                    check = false;
                    break;
                }
            }
            // if we get check as true
            // which means we found needle in haystack
            // then return the index i
            if(check==true){
                return i;
            }
        }
        // return -1
        return -1;
    }
};
