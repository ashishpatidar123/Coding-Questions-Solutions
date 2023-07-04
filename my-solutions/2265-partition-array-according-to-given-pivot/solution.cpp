class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int index = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==pivot){
                index = i;
                break;
            }
        }
        int n = nums.size();
        // for(int i=0; i<index; i++){
        //     if(nums[i]>pivot){
        //         cout<<"no";
        //         for(int j=i; j<index; j++){
        //             cout<<"yes";
        //             swap(nums[j],nums[j+1]);
        //         }
        //     }

        // }
        
        // for(int i=index+1; i<nums.size(); i++){
        //     if(nums[i]<=pivot){
        //         for(int j=i; j>index; j--){
        //             swap(nums[j],nums[j-1]);
        //         } 
        //     }
        // }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]==pivot){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
