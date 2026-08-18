class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.size();

        int count = 0;
        int ans1 = 0;

        int l=0;
        int l2=0;
        int count2=0;
        int ans2=0;

        for(int r=0; r<n; r++){

            if(answerKey[r] == 'F'){
                count++;
            }

            while(count > k){
                if(answerKey[l] == 'F'){
                    count--;
                }

                l++;
            }

            ans1 = max(ans1, r-l+1);

            if(answerKey[r] == 'T'){
                count2++;
            }

            while(count2 > k){
                if(answerKey[l2] == 'T'){
                    count2--;
                }

                l2++;
            }

            ans2 = max(ans2, r-l2+1);



        }
        // l=0;
        // count=0;
        // int ans2 = 0;
        // for(int r=0; r<n; r++){

        //     if(answerKey[r] == 'T'){
        //         count++;
        //     }

        //     while(count > k){
        //         if(answerKey[l] == 'T'){
        //             count--;
        //         }

        //         l++;
        //     }

        //     ans2 = max(ans2, r-l+1);

        // }

        return max(ans1, ans2);
        

        
    }
};
