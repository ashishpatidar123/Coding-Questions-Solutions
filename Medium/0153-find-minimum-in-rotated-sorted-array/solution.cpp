class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int n = arr.size();

        int mid = -1;

        int start = 0;
        int end = n-1;

        if(arr[0] < arr[n-1]){

           return arr[0];

        }
        int ans = arr[0];
        
        while(start < end){

            int mid = start + (end-start)/2;

            if(arr[mid] > arr[end]){
                start = mid+1;
            }
            else{
                end = mid;
            }

        }
        ans = min(ans, arr[start]);
        return ans;

    }
};
