class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int prev = INT_MIN;
        set<vector<int>>s;
        for(int i=0; i<n; i++){

            int target = -1*nums[i];
            if(i>0){
                if(nums[i] == prev){
                    continue;
                }
                prev = nums[i];

            }
            int left = i+1;
            int right = n-1;

            while(right > left){
                int sum = nums[left] + nums[right];

                if(sum == target ){
                    // ans.push_back({nums[i],nums[left],nums[right]});
                    s.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }

        }
        for(auto t:s){
            ans.push_back(t);
        }

        return ans;
        


    }
};
