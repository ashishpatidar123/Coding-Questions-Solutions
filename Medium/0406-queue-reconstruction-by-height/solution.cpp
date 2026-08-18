class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0; i<people.size(); i++){
            int height = people[i][0];
            int num = people[i][1];

            temp.push_back({height,{num,num}});
        }
        vector<vector<int>>ans;

        for(int i=0; i<temp.size(); i++){
            int person;
            int min = INT_MAX;
            pair<int,pair<int,int>>var;
            for(int i=0; i<temp.size(); i++){
                if(temp[i].second.second == 0 && temp[i].first<min){
                    min = temp[i].first;
                    var = temp[i];
                    temp[i].second.second == INT_MAX;
                }
            }
            for(int i=0; i<temp.size(); i++){
                if(temp[i].first <= min){
                    temp[i].second.second--;
                }
            }
            ans.push_back({var.first,var.second.first});

        }
        return ans;
    }
};
