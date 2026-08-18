class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip trailing spaces from the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};