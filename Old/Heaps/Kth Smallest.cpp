class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // create a max heap using priority queue
        priority_queue<int> pq;
        // push first k elements to it
        for(int i=l; i<k; i++){
            pq.push(arr[i]);
        }
        // now compare the rest of the elements of the array with the topmost element of
        // the queue 
        // since it is a max heap top element will be the maximum of all the elements
        // if the element is smaller than the top then pop the top and push the element
        for(int i=k; i<=r; i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        // now we got k smallest elements in out priority queue and the top one is the kth
        // smallest
        int ans = pq.top();
        return ans;
    }
};
