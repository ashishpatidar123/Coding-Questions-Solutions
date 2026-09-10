class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        vector<long long int>prefix(2*n+1, 0);

        for(int i=0; i<2*n; i++){
            prefix[i+1] = prefix[i] + nums[i%n];
        }

        for(int l=0; l<n; l++){
            int m = n + l;
            long long int last = prefix[m] - prefix[m -n/2];
            long long int first = prefix[m - n/2] - prefix[l];

            if(first > last) count++;
        }

        return count;
    }
};