class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int>ans;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i!=j){
        //             if(nums[i]+nums[j] == target){
        //                 return {i,j};
        //             }
        //         }
        //     }
        // }
        int left = 0;
        int right = n-1;
        vector<pair<int,int>>temp;
        for(int i=0; i<n; i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());


        while(right > left){
            int sum = temp[left].first + temp[right].first;

            if(target == sum){
                return {temp[left].second, temp[right].second};
            }
            else if(target > sum){
                left++;
            }
            else{
                right--;
            }
        }

        return {};
    }
};
