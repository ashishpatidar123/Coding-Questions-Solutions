class Solution
{   
    private: 
    void solve(vector<int>&A,vector<int>&temp,vector<vector<int>>&ans,int index){
        
        // first push the subarray
        ans.push_back(temp);
        // now add next remaining elements to our subarray
        for(int i=index; i<A.size(); i++){
            // push the current element
            temp.push_back(A[i]);
            // call for the next element
            solve(A,temp,ans,i+1);
            // backtracking step
            // remove the current element
            temp.pop_back();
        }
        //return when index become greater than or equal to size
        return;
        
    }
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        solve(A,temp,ans,index);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// second solution
void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
    if (index >= S.size()) {
        result.push_back(current);
        return;
    }
    // Ignore the current index.
    generateSubsets(S, index + 1, current, result);

    // Include the current index. 
    current.push_back(S[index]);
    generateSubsets(S, index + 1, current, result);
    current.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &S) {  
    vector<vector<int> > result; 
    vector<int> current;
    sort(S.begin(), S.end());
    generateSubsets(S, 0, current, result);
    sort(result.begin(), result.end());
    return result;
} 
