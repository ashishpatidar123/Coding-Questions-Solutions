vector<long long int> even;
vector<long long int> odd;
bool created = false;

void compute(){
    if(created){
        return;
    }

    created = true;

    for(int i=1; i<=100000; i++){
        string s = to_string(i);
        string s2 = s;
        reverse(s2.begin(), s2.end());

        string s_even = s + s2;
        long long int p_even  = stoll(s_even);
        if(p_even % 2 == 0){
            even.push_back(p_even);
        }
        else{
            odd.push_back(p_even);
        }

        string s_odd = s + s2.substr(1);
        long long int p_odd  = stoll(s_odd);
        if(p_odd % 2 == 0){
            even.push_back(p_odd);
        }
        else{
            odd.push_back(p_odd);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
}
class Solution {
public:
    bool check(long long int n){

        string s = to_string(n);

        if(s.length() == 1) return true;

        int i=0;
        int j=s.length()-1;

        while(j>i && s[i] == s[j]){
            i++;
            j--;
        }

        if(j>i) return false;
        return true;

    }
    long long minOperations(vector<int>& nums) {

        // int n = nums.size();

        // long long int ans = 0;

        // for(int i=0; i<n; i++){
        //     long long temp = nums[i];

        //     long long int count1 = 0;

        //     while(!check(temp)){
        //         temp += 2;
        //         count1++;
        //     }

        //     temp = nums[i];
        //     long long int count2=0;
        //     while(temp >=0 && !check(temp)){
        //         temp -= 2;
        //         count2++;
        //     } 

        //     ans += min(count1, count2);
        // }

        // return ans;

        compute();

        long long int ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            long long int x = nums[i];

            const vector<long long int>* temp;

            if(x%2 == 0){
                temp = &even;
            }
            else{
                temp = &odd;
            }

            auto it = lower_bound(temp->begin(), temp->end(), x);

            long long int min_diff = 2e18;

            if(it != temp->end()){
                min_diff = min(min_diff, abs(*it - x));
            }
            if(it != temp->begin()){
                min_diff = min(min_diff, abs(*(it-1) - x));
            }

            ans += (min_diff/2);
        }

        return ans;
    }
};