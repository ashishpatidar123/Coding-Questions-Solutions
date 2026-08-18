class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        int n = s.length();
        int m = chars.length();

        int max_sum = INT_MIN;
        int sum = 0;

        for(int i=0; i<n; i++){

            char c = s[i];
            int val = 0;
            bool found = false;

            for(int j=0; j<m; j++){
                if(chars[j] == c){
                    found = true;
                    val = vals[j];
                }
            }
            if(!found){
                val = c - 'a' + 1;
            }

            if(val + sum > 0){
                sum += val;
                max_sum = max(max_sum, sum);
            }
            else{
                max_sum = max(max_sum, sum);
                sum = 0;
            }

        }
        return max_sum;
    }
};
