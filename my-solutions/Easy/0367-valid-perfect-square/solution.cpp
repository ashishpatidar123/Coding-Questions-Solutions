class Solution {
public:
    bool isPerfectSquare(int num) {

        long long int left = 0;
        long long int right = num;

        if(num==1){
            return true;
        }
        while(left+1<right){
            
            long long int mid = left + (right-left)/2;

            if(mid*mid == num){
                return true;
            }
            else if(mid*mid > num){
                right = mid;
            }
            else{
                left = mid;
            }

        }

        return false;
        
    }
};
