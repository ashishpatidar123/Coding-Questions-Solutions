class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();

        int sum = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                sum += nums[i];
            }
            else{
                break;
            }
        }
        set<int>s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int ans = sum; 
        for(int i=sum; i<=51; i++){
            if(s.find(i) == s.end()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
