class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        long long int total = 0;

        
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        int k = n - n/2;
        long long int windowTotal = 0;

        for(int i=0; i<k; i++){
            windowTotal += nums[i];
        }

        for(int l=0; l<n; l++){
            if(2*windowTotal > total){
                count++;
            }
            windowTotal -= nums[l];
            windowTotal += nums[(l+k)%n];
        }
        return count;
    }
};