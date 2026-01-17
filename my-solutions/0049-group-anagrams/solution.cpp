class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        

        int n = strs.size();
        vector<pair<string,int>>temp;
        for(int i=0; i<n; i++){

            string s = strs[i];
            sort(s.begin(),s.end());
            temp.push_back({s,i});

        }
        sort(temp.begin(),temp.end());

        vector<vector<string>>ans;
        string prev = temp[0].first;
        vector<string>arr;
        arr.push_back(strs[temp[0].second]);
        for(int i=1; i<n; i++){
            if(temp[i].first == prev){
                arr.push_back(strs[temp[i].second]);
            }
            else{
                prev = temp[i].first;
                ans.push_back(arr);
                arr = {};
                arr.push_back(strs[temp[i].second]);
            }
        }
        ans.push_back(arr);
        return ans;
    }
};
