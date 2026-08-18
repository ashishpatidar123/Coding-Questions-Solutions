class Solution {
public:
    unsigned int countSetBits(int n){
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    int hammingDistance(int x, int y) {

        int ans = x^y;

        return countSetBits(ans);
        
    }
};
