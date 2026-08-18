class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        
        int n = arr.size();
        int max_len = -1;
        if(n==1){
            return 1;
        }
        if(n==2){
            if(arr[0]==arr[1]){
                return 1;
            }
            else{
                return 2;
            }
        }
        bool sign = true; 

        int curr = 0;
        
        for(int i=1; i<n; i++){
            
            bool temp = sign;

            if(arr[i]>arr[i-1]){
                temp = true;
                if(temp == sign){
                    max_len = max(max_len, curr);
                    curr = 1;

                }
                else{
                    curr += 1;
                    max_len = max(max_len, curr);
                    sign = temp;
                }
            }
            else if(arr[i] < arr[i-1]){
                temp = false;
                    if(temp == sign){
                    max_len = max(max_len, curr);
                    curr = 1;

                }
                else{
                    curr += 1;
                    max_len = max(max_len, curr);
                    sign = temp;
                }
            }
            else if(arr[i]==arr[i-1]){
                curr = 0;
                max_len = max(max_len, curr);
                sign = false;
            }


        }
        return max_len+1;

    }
};
