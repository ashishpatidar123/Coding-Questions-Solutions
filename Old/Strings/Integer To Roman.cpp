string Solution::intToRoman(int A) {
    vector<pair<string,int>> v;
    v.push_back({"I",1});
    v.push_back({"IV",4});
    v.push_back({"V",5});
    v.push_back({"IX",9});
    v.push_back({"X",10});
    v.push_back({"XL",40});
    v.push_back({"L",50});
    v.push_back({"XC",90});
    v.push_back({"C",100});
    v.push_back({"CD",400});
    v.push_back({"D",500});
    v.push_back({"CM",900});
    v.push_back({"M",1000});
    
    int n = v.size();
    string res = "";
    for(int i=n-1; i>=0; i--){
        int num = v[i].second;
        string str = v[i].first;
        if(A/num){
            int count = A/num;
            while(count>0){
                res = res + str;
                count--;
            }
            A = A%num;
        }  
    }
    return res;
}
