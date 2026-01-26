class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        set<int>s;

        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int count = s.size();
        int ans = 0;
        
        // for(int i=0; i<n; i++){
        //     set<int>t;
        //     for(int j=i; j<n; j++){
        //         t.insert(nums[j]);
        //         if(t.size() == count){
        //             ans += n-j;
        //             break;
        //         }
        //     }
        // }
        unordered_map<int,int>freq;

        int l = 0;
        int distinct = 0;

        for(int r = 0; r<n; r++){
            freq[nums[r]]++;
            if(freq[nums[r]] == 1){
                distinct++;
            }

            while(distinct == count){

                ans += n-r;

                freq[nums[l]]--;

                if(freq[nums[l]] == 0){
                    distinct--;
                }
                l++;

            }
        }
        return ans;
        
    }
};
