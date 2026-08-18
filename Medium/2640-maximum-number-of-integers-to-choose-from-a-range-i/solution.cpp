class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxsum) {
        int nn = banned.size();
     set <int> s;
        for(int i=0;i<nn;i++) s.insert(banned[i]);
        int currsum=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s.find(i) !=s.end()) continue;
            if(currsum+i<=maxsum){
                ans++;
                currsum+=i;
            }
        }
        return ans;

    }
};

/*
1 3 6 10
15
1000000



*/
