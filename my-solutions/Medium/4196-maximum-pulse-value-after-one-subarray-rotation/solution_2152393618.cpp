class Solution {
public:
    
    long long maxValue(vector<int>& nums) {

        int n = nums.size();
        long long int curr = 0;
        long long int t = 1;

        vector<long long int>prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + t*nums[i];
            t = -1*t;
        }

        curr = prefix[n];
        long long int max_change = 0;
        long long int max_even = -1e18;
        long long int max_odd = -1e18;

        for(int r=1; r<n; r++){
            int l = r-1;

            if(l%2 == 0){
                max_even = max(max_even, prefix[l+1]);
                max_odd = max(max_odd, prefix[l]);
            }
            else{
                max_even = max(max_even, prefix[l]);
                max_odd = max(max_odd, prefix[l+1]);
            }

            long long int temp = -1e18;
            if(r%2==0){
                temp = 2*(max_even - prefix[r+1]);
            }
            else{
                temp = 2*(max_odd - prefix[r+1]);
            }

            max_change = max(max_change, temp);
        }


        return curr + max_change;

         
        
    }
};