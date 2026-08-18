class Solution {
public:
    int mod = 1e9 + 7;
    int fact[100002]; // to store the factorial results, to reduce over computations

    int multiply(int a, int b){

        long long int ans = ((long long) (a%mod)*(b%mod))%mod; // only works if both a and b are smaller than mod 
        // if larger then can't use this. In that case multiply first and then take mod
        return ans;
    }

    void factorial(){
        fact[0] = 1;
        for(int i=1; i<=100001; i++){
            fact[i] = multiply(fact[i-1],i);
        }
    }
    int binaryExponentiation(int a, int b){
        if(!b){
            return 1;
        }
        int result = binaryExponentiation(a, b/2);

        if(b&1){
            int res = multiply(a, multiply(result, result));
            return res;
        }
        else{
            int res = multiply(result, result);
            return res;

        }
    }
    int moduloInverse(int a){
        int ans = binaryExponentiation(a, mod-2);
        return ans;
    }

    int count(string str){
        vector<int>freq(26,0);
        int n = str.length();

        for(int i=0; i<n; i++){
            freq[str[i]-'a']++;
        }

        int ans = fact[n];

        int res = 1;

        for(int i=0; i<26; i++){
            res = multiply(res, fact[freq[i]]);
        }

        return multiply(ans, moduloInverse(res));

    }
    int countAnagrams(string s) {
        
        factorial();

        istringstream ss(s);

        string word;
        int ans = 1;

        while(ss >> word){
            ans = multiply(ans, count(word));
        }
        return ans;

    }
};
