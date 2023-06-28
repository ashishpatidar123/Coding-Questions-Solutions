int n = A.size();
    
    // Find the first element that is smaller than its next element
    int i = n - 2;
    while (i >= 0 && A[i] >= A[i + 1]) {
        i--;
    }
    
    // If no such element is found, the given permutation is the last one
    if (i < 0) {
        std::reverse(A.begin(), A.end());
        return A;
    }
    
    // Find the smallest element greater than A[i] in the suffix
    int j = n - 1;
    while (j > i && A[j] <= A[i]) {
        j--;
    }
    
    // Swap A[i] and A[j]
    std::swap(A[i], A[j]);
    
    // Reverse the suffix
    std::reverse(A.begin() + i + 1, A.end());
    
    return A;
