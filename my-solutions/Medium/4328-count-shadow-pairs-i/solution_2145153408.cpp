// class Solution {
// public:
//     std::vector<int> findNextSmallerIndices(const std::vector<int>& arr) {
//         int n = arr.size();
//         std::vector<int> result(n, -1);
//         std::stack<int> st;

//         for (int i = n - 1; i >= 0; --i) {
//             // Pop elements that are greater than or equal to the current element
//             while (!st.empty() && arr[st.top()] >= arr[i]) {
//                 st.pop();
//             }

//             // If stack is not empty, the top element is the closest smaller index
//             if (!st.empty()) {
//                 result[i] = st.top();
//             }

//             // Push the current index onto the stack
//             st.push(i);
//         }

//         return result;
//     }
//     int count_occurrences_to_right(const std::unordered_map<int, std::vector<int>>& index_map, int val, int i, int k) {
//         if (i >= k) return 0;
        
//         auto it = index_map.find(val);
//         if (it == index_map.end()) return 0;

//         const auto& indices = it->second;
//         auto lower = std::lower_bound(indices.begin(), indices.end(), i + 1);
//         auto upper = std::upper_bound(indices.begin(), indices.end(), k);

//         return std::distance(lower, upper);
//     }

//     long long shadowPairs(vector<int>& nums) {

//         int n = nums.size();
//         long long int ans = 0;
//         vector<int> indexes = findNextSmallerIndices(nums);
//         unordered_map<int, vector<int>> index_map;
//         for (int i = 0; i < nums.size(); ++i) {
//             index_map[nums[i]].push_back(i);
//         }

//         vector<long long int>temp(n, 0);
//         temp[n-1] = 0;
        
//         unordered_map<int, int> count;
//         count[nums[n-1]]++;

//         for(int i=n-2; i>=0; i--){
//             if(nums[i] < nums[i+1]){
//                 int index = indexes[i];
//                 if(indexes[i] != -1){
//                     temp[i] = index - i - 1;
                    
//                     int c = count_occurrences_to_right(index_map, nums[i], i, index);
//                     count[nums[i]] = c; 
//                 }
//                 else{
                    
//                     temp[i] = n - i - 1;
//                 }
                
//                 if(count.find(nums[i]) != count.end()){
                    
//                     temp[i] = temp[i] - count[nums[i]];
//                 }
//             }
//             if(nums[i] == nums[i+1]){
//                 temp[i] = temp[i+1];
//             }
//             count[nums[i]]++;
//         }
//         for(int i=0; i<n; i++){
//             // cout<<temp[i]<<" ";
//             ans += temp[i];
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        vector<long long int> temp(n, 0);
        stack<int> st; 

        for (int i = n - 1; i >= 0; --i) {
            
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            int index = st.empty() ? n : st.top();

            if(index == n){
                temp[i] = n - i - 1;
            }
            else if(nums[index] == nums[i]){
                temp[i] = temp[index] + (index - i - 1);
            }
            else{
                temp[i] = index - i - 1;
            }

            ans += temp[i];
            st.push(i);
        }
        
        return ans;
    }
};