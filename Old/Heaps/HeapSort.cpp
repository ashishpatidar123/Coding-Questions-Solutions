class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
       int smallest = i;
       int left = 2*i;
       int right = 2*i+1;
       
       if(left<n && arr[smallest]<arr[left]){
           smallest = left;
       }
       if(right<n && arr[smallest]<arr[right]){
           smallest = right;
       }
       if(smallest!=i){
           swap(arr[smallest],arr[i]);
           heapify(arr,n,smallest);
       }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2; i>=0; i--){
            heapify(arr,n,i);
        }
        
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {   
        buildHeap(arr,n);
        int size = n;
        while(size>1){
            swap(arr[size-1],arr[0]);
            size--;
            heapify(arr,size,0);
        }
    }
};
