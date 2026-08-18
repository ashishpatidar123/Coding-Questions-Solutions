class Solution

{   
    private: 
    void backtrack(vector<int>& arr, int start, vector<int>& subset, vector<vector<int>>& subsets) {
        // Add the current subset to the list of subsets
        subsets.push_back(subset);
        
        // Explore further subsets by considering each element
        for (int i = start; i < arr.size(); i++) {
            // Skip duplicates to maintain uniqueness
            if (i > start && arr[i] == arr[i - 1])
                continue;
            
            // Include the current element in the subset
            subset.push_back(arr[i]);
            
            // Explore further subsets with the next element
            backtrack(arr, i + 1, subset, subsets);
            
            // Remove the current element from the subset for the next iteration
            subset.pop_back();
        }
    }
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // Sort the array to ensure subsets are sorted
        sort(arr.begin(), arr.end());
        
        // List to store unique subsets
        vector<vector<int>> subsets;
        vector<int> subset;
        // Call the backtrack function to find all subsets
        backtrack(arr, 0, subset, subsets);
        
        return subsets;
        
    }
};
