class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        int curr = 0;
        int start = 0;

        for(int i=0; i<n; i++){
            int net = gas[i] - cost[i];

            total += net;
            curr += net;

            if(curr < 0){
                curr = 0;
                start = i+1;
            }
        }

        if(total < 0) return -1;

        return start;
    }
};