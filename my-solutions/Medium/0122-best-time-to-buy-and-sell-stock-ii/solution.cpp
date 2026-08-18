class Solution {
public:

    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        

        if(n==1) return 0;
        if(n==2) return max(0, prices[1]-prices[0]);

        int ans = 0;

        for(int i=0; i<n-1; i++){
            if(prices[i+1]>prices[i]){
                ans += prices[i+1]-prices[i];
            }
        }

        return ans;



    }
};
