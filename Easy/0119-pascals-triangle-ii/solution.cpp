class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>>  ans;
        vector<int> first(1,1);
        vector<int> second(2,1);
        if(numRows==0){
            return first;
        }
        ans.push_back(first);
        ans.push_back(second);
        for(int i=2; i<numRows+1; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1; j<i; j++){
                temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        vector<int> temp;
        temp = ans[numRows];
        return temp;
    }
};
