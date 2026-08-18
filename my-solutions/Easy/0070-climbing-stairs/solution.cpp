class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        else if(n==2 || n==1){
            return n;
        }
        int a = 1;
        int b = 1;
        int c = 0;

        for(int i=2; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};
