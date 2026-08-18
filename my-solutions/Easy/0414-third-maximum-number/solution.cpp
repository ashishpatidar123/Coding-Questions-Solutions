class Solution {
public:
    int thirdMax(vector<int>& nums) {

        int n = nums.size();

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        bool check = false;

        for(int i=0; i<n; i++){
            int x = nums[i];
            if(x == INT_MIN){
                check = true;
            }
            if(x > max1){
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if(x == max1){
                continue;
            }
            else if(x > max2){
                max3 = max2;
                max2 = x;
            }
            else if(x == max2){
                continue;
            }
            else if(x > max3){
                max3 = x;
            }
            else if(x ==  max3){
                continue;
            }
            
        }

        if(max3 == INT_MIN && check == false){

            return max1;
            
        }
        else if(max2 == INT_MIN && check == true && max1 != INT_MIN){
            return max1;
        }
        
        return max3;
        
    }
};
