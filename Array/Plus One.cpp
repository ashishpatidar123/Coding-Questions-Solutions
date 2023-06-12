class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int sum = 0;
        int carry = 0;
        int n = digits.size();
        //traverse through the array
        for(int i=n-1; i>=0; i--){
            // for the last index add 1 to it
            if(i==n-1){
                sum = digits[i] + 1;
                // push sum%10 to ans vector
                ans.push_back(sum%10);
                // carry will be sum/10
                carry = sum/10;
            }
            // for other indexes simply add carry to the digits
            else{
                sum = digits[i]+carry;
                ans.push_back(sum%10);
                carry = sum/10;
            }
        }
        // if carry is not zero the push it to the ans vector
        if(carry!=0){
            ans.push_back(carry);
        }
        // reverse the ans vector
        reverse(ans.begin(),ans.end());
        // return ans
        return ans;
    }
};
