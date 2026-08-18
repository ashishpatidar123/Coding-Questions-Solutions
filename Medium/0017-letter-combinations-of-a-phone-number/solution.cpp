class Solution {
    void generate(string digits, vector<string> &output, int index, string s,string maps[10]){
        if(index>=digits.length()){
            output.push_back(s);
            return ;
        }

        int digit = digits[index]-'0';
        int value = maps[digit].length();
        string temp = maps[digit];
        for(int i=0; i<value; i++){
            s.push_back(temp[i]);
            generate(digits,output,index+1,s,maps);
            s.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        string s ;
        if(digits.length()==0){
            return output;
        }
        string maps[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        generate(digits,output,index,s,maps);
        return output;
        
    }
};
