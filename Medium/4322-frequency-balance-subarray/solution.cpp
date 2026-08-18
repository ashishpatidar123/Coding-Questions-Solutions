class Solution {
public:
    int getLength(vector<int>& arr) {
        
        int n = arr.size();
        int maxi = 1;

        

        for(int i=0; i<n; i++){
            int distinct = 0;
            unordered_map<int, int>count;

            unordered_map<int, int>freq;
            for(int j=i; j<n; j++){
                int currFreq = count[arr[j]];
                
                if(freq.find(currFreq) != freq.end()){
                    freq[currFreq]--;
                    if(freq[currFreq] == 0){
                        freq.erase(currFreq);
                    }
                }
                count[arr[j]]++;
                int newFreq = count[arr[j]];
                freq[newFreq]++;
                if(newFreq == 1){
                    distinct++;
                }


                if(distinct == 1){
                    maxi = max(maxi, j-i+1);
                }
                else{
                    if(freq.size() == 2){
                        vector<int>temp;
                        for(auto t:freq){
                            temp.push_back(t.first);
                        }

                        if(temp[0] == 2*temp[1] || temp[1] == 2*temp[0]){
                            maxi = max(maxi, j-i + 1);
                        }
                    }
                }
            }
        }
        return maxi;
    }
};
