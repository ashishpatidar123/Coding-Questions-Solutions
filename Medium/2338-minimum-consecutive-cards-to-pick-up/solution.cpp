class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int n = cards.size();
        unordered_map<int,int>index;

        int mini = n+1;

        for(int i=0; i<n; i++){

            if(index.find(cards[i]) == index.end() ){
                index[cards[i]] = i;
            }
            else{
                int len = i - index[cards[i]]+1;
                index[cards[i]] = i;
                mini = min(mini, len);
            }
        }
        if(mini == n+1){
            return -1;
        }
        return mini;
    }
};
