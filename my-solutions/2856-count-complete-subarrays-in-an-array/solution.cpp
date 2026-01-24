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
        
        for(int i=0; i<n; i++){
            set<int>t;
            for(int j=i; j<n; j++){
                t.insert(nums[j]);
                if(t.size() == count){
                    ans += n-j;
                    break;
                }
            }
        }
        return ans;
        
    }
};
