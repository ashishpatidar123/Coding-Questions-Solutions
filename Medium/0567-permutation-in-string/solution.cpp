class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);

        for(int i=0; i<s1.length(); i++){
            count1[s1[i]-'a']++;
        }
        int windowSize = s1.length();

        if(s1.length()>s2.length()){
            return false;
        }
        
        // vector<int> count2(26,0);
        for(int i=0; i<s2.length()-windowSize+1; i++){
            
            vector<int> count3(26,0);
            for(int j=i; j<i+windowSize; j++){
                // count2[s2[j]-'a']++;
                count3[s2[j]-'a']++;
            }
            if(count1 == count3){
                return true;
            }
            // count2[s2[i]-'a']--;
            continue;

        }

        // if(count1 == count2){
        //     return true;
        // }
        return false;
    }
};
