//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	    }
	    // finding if the subset with sum exist or not
	    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
	    for(int i=1; i<=sum; i++){
	        dp[0][i]=false;
	    }
	    for(int i=0; i<=n; i++){
	        dp[i][0]=true;
	    }
	    for(int i=1; i<=n; i++){
	        for(int j=0; j<=sum; j++) {
	           if(arr[i-1]<=j){
	               dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
	           }
	           else{
	               dp[i][j] = dp[i-1][j];
	           }
	        }
	    }
	    // the last row of our dp will have results for the problem like can we have subset with sum 0 1 2 till sum of our complete array
	    // so we will check only for positive entries because these are the only possible subset sums we can generate
	    // now we will store these entries to an array
	    // we will only store the first half entries that is entries which are less than or equal to sum/2
	    vector<int> possibleSums;
	    for(int i=0; i<=sum; i++){
	        if(i<=sum/2 && dp[n][i]==true){
	            possibleSums.push_back(i);
	           // cout<<i<<" ";
	        }
	    }
	   // cout<<sum<<" ";
	   // now we will find the minimum sum-2*s1 value from those entries
	    int ans = INT_MAX;
	    for(int i=0; i<possibleSums.size(); i++){
	        ans = min(ans,sum-2*possibleSums[i]);
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
