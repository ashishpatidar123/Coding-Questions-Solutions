class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>group(n+1);
        for(int i=0; i<n; i++){
            group[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;

        for(int i=1; i<=n; i++){
            if(group[i].size()!=0){
                int s = group[i].size();
                vector<int>temp;
                for(int j=0; j<s; j++){
                    temp.push_back(group[i][j]);
                    if(temp.size()==i){
                        ans.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        return ans;
    }
};
