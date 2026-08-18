class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        long long int left = 0;
        long long int right = arr.size();
        long long int n = arr.size();

        while(left+1<right){
             
            long long int mid = left + (right-left)/2;

            if(mid>0 && mid!=n-1 && arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(mid!=n-1 && arr[mid]<=arr[mid+1]){
                left = mid;
            }
            else if(mid>0 && arr[mid]<arr[mid-1]){
                right = mid;
            }

        }

    return 0;
        
    }
};
