class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int start = 0;
        int end= 0;
        int max_len = -1;
        int len = 0;
        int zerocount = 0;
        while(end<nums.size()){
              
            if(nums[end] == 0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[start]==0){
                    zerocount--;
                }
                start++;
            }
            len = end - start + 1;
            if(len>max_len){
                max_len = len;
            }
            end++;
                
        }
        return max_len;
        // deque<int> dq;
        // int zerocount = 0;
        // int max = 0;
        // int len = 0;

        // for(int i=0; i<nums.size(); i++){
            
        //     dq.push_front(nums[i]);
        //     if(nums.size()==0){
        //         zerocount++;
        //     }
        //     while()
        // }
    }
};
