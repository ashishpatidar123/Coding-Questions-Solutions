class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp = nums;

        sort(temp.begin(),temp.end());

        
        
        int med = 0;
        if(n%2==0){
            med = n/2;
        }
        else{
            med = n/2 + 1;
        }
        int k = med-1;
        int j = n-1;
        for(int i=0; i<n; i++){
            if(i%2==0){
                nums[i] = temp[k];
                k--;
            }
            else{
                nums[i] = temp[j];
                j--;
            }
        }


        
        
        
        



    }
};
