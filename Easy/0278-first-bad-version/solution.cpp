// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        
        long long int left = 0;
        long long int right = pow(2,31)-1;

        while(right>left+1){

            long long int m = left + (right-left)/2;

            if(isBadVersion(m)){
                right = m;
            }
            else{
                left = m;
            }

        }

        return right;
    }
};
