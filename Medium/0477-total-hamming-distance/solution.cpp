class Solution {
public:
    // unsigned int countSetBits(int n){
    //     unsigned int count = 0;
    //     while (n) {
    //         n &= (n - 1);
    //         count++;
    //     }
    //     return count;
    // }
    int BitsSetTable256[256];
    void initialize() 
    { 

        // To initially generate the 
        // table algorithmically 
        BitsSetTable256[0] = 0; 
        for (int i = 0; i < 256; i++)
        { 
            BitsSetTable256[i] = (i & 1) + 
            BitsSetTable256[i / 2]; 
        } 
    } 
 
    int countSetBits(int n) 
    { 
        return (BitsSetTable256[n & 0xff] + 
                BitsSetTable256[(n >> 8) & 0xff] + 
                BitsSetTable256[(n >> 16) & 0xff] + 
                BitsSetTable256[n >> 24]); 
    }   
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size();
        long long int ans = 0;
        // initialize();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int temp = nums[i]^nums[j];
        //         ans += countSetBits(temp);
        //     }
        // }
        // return ans;

        for(int b=0; b<32; b++){
            int count1 = 0;

            for(int x:nums){
                if(x&(1 << b)){
                    count1++;
                }
            }
            int count0 = n - count1;

            ans = ans + (long long int)count1*count0;
        }
        return ans;

    }
};
