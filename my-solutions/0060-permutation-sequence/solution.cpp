class Solution {
    void generate(string &s, vector<string> &ans, int index){
        if(index>=s.length()){
            ans.push_back(s);
            return ;
        }
        for(int i=index; i<s.length(); i++){
            swap(s[index],s[i]);
            generate(s,ans,index+1);
            swap(s[index],s[i]);
        }
        
    }
public:
    string getPermutation(int n, int k) {
        string s ="";
        while(n>0){
            char c = n + '0';
            s.push_back(c);
            n--;
        }
        
        // vector<string> ans;
        // int index = 0;
        // generate(s,ans,index);
        // string temp ;
        // sort(ans.begin(),ans.end());
        // temp = ans[k-1];
        // return temp;
        while(k>0){
            next_permutation(s.begin(),s.begin()+s.length());
            k--;
        }
        return s;
    }
};
