class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0; 
        int r = arr.size()-1;
        int mid = (l+r)/2;
        int ans = 0;
        while(l<=r){
            if(arr[mid]>arr[mid+1]){
                ans = mid;
                r = mid-1;
            }
            else if(arr[mid]<arr[mid+1]){
                l = mid+1;
            }
            mid = (l+r)/2;
            
        }
        return ans;

    }
};
