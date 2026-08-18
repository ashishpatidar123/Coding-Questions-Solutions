class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(),special.end());
        int count = 0;
        int max = special[0]-bottom;
        int i=0;
        for(i=0; i<special.size()-1; i++){
            count = special[i+1]-special[i]-1;
            if(count>max){
                max = count;
            }
        }
        count = top - special[i];
        if(count>max){
            max = count;
        }
        return max;
    }
};
