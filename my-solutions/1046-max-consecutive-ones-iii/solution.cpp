class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int>prefix(n+1,0);

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + (abs(1-nums[i]));
        }
        int l=0;
        int r=0;
        int ans = 0;
        while(l <= r && r<n){
            if(prefix[r+1]-prefix[l] <= k){
                ans = max(ans, r+1-l);
                r++;
            }
            else{
                l++;
                r++;
            }
        }
        return max(ans, n-l);
    }
};
