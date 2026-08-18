class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int>index;

        vector<int>prefix(n+1,0);

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]+nums[i];
        }

        int maxi = -1;
        int idx = 0;
        for(int i=0; i<n; i++){

            if(index.find(nums[i]) == index.end() || index[nums[i]] < idx){

                index[nums[i]] = i;
                int sum = prefix[i+1] - prefix[idx];
                maxi = max(sum, maxi);

            }
            else{
                int sum = prefix[i]-prefix[idx];
                idx = index[nums[i]]+1;
                index[nums[i]]=i;
                maxi = max(maxi, sum);
            }
        }

        return maxi;
        
    }
};
