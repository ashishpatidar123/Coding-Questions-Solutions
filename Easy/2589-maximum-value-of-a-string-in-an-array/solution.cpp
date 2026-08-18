class Solution {
public:
    int maximumValue(vector<string>& strs) {

        int n = strs.size();
        int maxi = -1;
        for(int i=0; i<n; i++){
            int len = strs[i].size();

            bool check = true;
            int sum = 0;
            int factor = 1;

            for(int j=0; j<len; j++){
                if(strs[i][j] >= 'a' && strs[i][j] <= 'z'){
                    maxi = max(maxi, len);
                    check = false;
                }
            }
            if(check){
                for(int j=len-1; j>=0; j--){
                    int dig = strs[i][j] - '0';
                    sum += dig*factor;
                    factor *= 10;
                }
                maxi = max(maxi, sum);
            }
       } 
       
       return maxi;
    }

};
