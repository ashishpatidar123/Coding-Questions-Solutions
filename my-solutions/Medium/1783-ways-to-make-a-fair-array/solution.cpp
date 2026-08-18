class Solution {
public:
    int waysToMakeFair(vector<int>& A) {
        int n = A.size();
        long long int even = 0;
        long long int odd = 0;
        long long int leftodd[n];
        long long int rightodd[n];
        long long int lefteven[n];
        long long int righteven[n];

        for(int i=0; i<n; i++){
            leftodd[i] = odd;
            lefteven[i] = even;
            if(i%2!=0){
                odd += A[i];
            }
            else{
                even += A[i];
            }
        }
        odd = 0;
        even = 0;

        for(int i = n-1; i>=0; i--){
            rightodd[i] = odd;
            righteven[i] = even;
            if(i%2==0){
                even += A[i];
            }
            else{
                odd += A[i];
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(leftodd[i] + righteven[i] == lefteven[i] + rightodd[i]){
                count++;
            }
        }
        return count;
    }
};
