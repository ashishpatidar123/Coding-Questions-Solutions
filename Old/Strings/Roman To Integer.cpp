int Solution::romanToInt(string A) {
    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int res = 0;
    for(int i=0; i<A.length(); i++){
        if(i+1<A.length() && m[A[i]]<m[A[i+1]]){
            res -= m[A[i]];
        }
        else{
            res += m[A[i]];
        }
    }
    return res;
}
