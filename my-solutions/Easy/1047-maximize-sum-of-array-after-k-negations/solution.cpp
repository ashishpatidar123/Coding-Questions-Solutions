class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        

        int n = nums.size();

        
        
        vector<int>neg;
        vector<int>pos;

        int index = -1;
        bool check = false;

        for(int i=0; i<n; i++){
            if(nums[i] >=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        sort(neg.begin(),neg.end());
        sort(pos.begin(),pos.end());

        int m = pos.size();
        int l = neg.size();

        for(int i=0; i<l; i++){
            if(k > 0){
                neg[i] = -1 * neg[i];
                k--;
            }
        }
        int sum = 0;
        int mini = 0;
        if(k%2!=0){
            if( l >=1 && m > 0){
                mini = min(neg[l-1],pos[0]);
            }
            else if(l==0){
                mini = pos[0];
            }
            else if(m == 0){
                mini = neg[l-1];
            }
        }
        for(int i=0; i<l; i++){
            sum += neg[i];
        }
        for(int j=0; j<m; j++){
            sum += pos[j];
        }
        if(k%2!=0){
            sum -= 2 * mini;
        }
        
        return sum;
        
        
       

    }
};
