class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {      
       vector<int> ans;
       stack<int> s;
       
       for(int j=nums2.size()-1; j>=0; j--){
       while(s.empty()!=1&&nums2[s.top()]<=nums2[j]){
                                s.pop();
                    }
                    
                    if(s.empty()){
                        ans.push_back(-1);
                    }             
                    
                    else {
                        ans.push_back(nums2[s.top()]);
                    }
                    
                    s.push(j); 
        }
        int x = nums2.size();
        vector<int> out;
        for(int i=0; i<nums1.size(); i++){
           for(int j=0; j<nums2.size(); j++){
               if(nums1[i]==nums2[j]){
                    
                    out.push_back(ans[x-1-j]);
   
               }
           }
       }
       return out;
       
    }
    
    
};
