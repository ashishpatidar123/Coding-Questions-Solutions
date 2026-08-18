class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> count; 
    

        int n = nums.size();
        int maxi = -1;
        int deg = INT_MAX;

        for (int i = 0; i < n; i++) {
            if(count.find(nums[i]) == count.end()) {
                count[nums[i]] = {1, i, i}; 
            } 
            else{
                count[nums[i]][0]++; 
                count[nums[i]][2] = i; 
            }
            maxi = max(maxi, count[nums[i]][0]); 
        }

        
        for (auto &p : count) {
            if (p.second[0] == maxi) {
                deg = min(deg, p.second[2] - p.second[1] + 1);
            }
        }
        return deg;
    }
};

