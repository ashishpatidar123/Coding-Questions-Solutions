class Solution {
public:
    static bool comparator(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();

        priority_queue<pair<int,int>>pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
            
        }

        
        vector<pair<int,int>>ans; 

        while(k > 0){
            pair<int,int> temp = pq.top();
            ans.push_back(temp);
            pq.pop();
            k--;
        }
        sort(ans.begin(),ans.end(),comparator);
        vector<int>temp;
        int l = ans.size();
        for(int i=0; i<l; i++){
            temp.push_back(ans[i].first);
        }

        return temp;
        
    }
};
