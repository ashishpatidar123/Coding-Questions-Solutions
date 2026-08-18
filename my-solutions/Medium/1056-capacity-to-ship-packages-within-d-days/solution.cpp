class Solution {
private: 
    bool isPossible(vector<int>&weights,int days, int n, int mid){

        int count = 1;
        int wt = 0;

        for(int i=0; i<n; i++){
            if(wt + weights[i]<=mid){
                wt += weights[i];
            }
            else{
                count++;
                if(count>days || mid<weights[i]){
                    return false;
                }
                wt = weights[i];
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int n = weights.size(); 
        for(int i=0; i<n; i++){
            sum += weights[i];
        }
        int start = 0;
        int end = sum;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start<=end){
            
            if(isPossible(weights,days,n,mid)){
                end = mid-1;
                ans = mid;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
};
