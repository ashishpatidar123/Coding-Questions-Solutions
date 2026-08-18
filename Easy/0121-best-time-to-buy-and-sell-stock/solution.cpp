class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int max_price = prices[n-1];
        int max_profit = 0;
        for(int i=n-1; i>=0; i--){
            
            max_price = max(max_price,prices[i]);
            prices[i] = max(0, max_price - prices[i]);
            max_profit = max(max_profit,prices[i]);

        }

        return max_profit;

    }
};
