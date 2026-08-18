class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& p) {
        int n = p.size();
        int flag = 0;
        if(n==2){
            flag=1;
        }
        else if(p[0][0]-p[1][0]==0){
            for(int i=2; i<n; i++){
                if(p[i][0]==p[1][0]){
                    flag = 1;
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
        else {
            float m = float((p[0][1]-p[1][1]))/(p[0][0]-p[1][0]);
            cout<<m;
            float c = p[0][1] - m*p[0][0];
            cout<<c;
            for(int i=2; i<n; i++){
                if(c==0){
                    if(float(p[1][1])/p[1][0]==float(p[i][1])/p[i][0]){
                        flag=1;
                    }
                    else {
                        flag=0;
                        break;
                    }
                }
                else if(p[i][1]==m*p[i][0]+c){
                    flag=1;
                }
                else {
                    flag=0;
                    break;
                }
            }
        }
        
        if(flag){
            return true;
        } 
        else return false;
    }
};
