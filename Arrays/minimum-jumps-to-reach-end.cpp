// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    // TC - O(n)
    // SC - O(1)
    int minJumps(int arr[], int n){
        // Your code here
        int steps = arr[0];    //number of remiainig steps to be checked for
        int jumps = 1;         //number of jumps (always atleast 1 jump is required)
        int maxReach = arr[0];  //max reachable index from the current pos
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;
        for(int i = 1; i < n; ++i) {
            maxReach = max(maxReach, arr[i] + i);
            steps--;
            if(i == n - 1) return jumps;
            if(steps == 0) {
                jumps++;
                if(maxReach <= i) return -1;
                steps = maxReach - i;
            }
        }
        return -1;
    }

    // TC - O(n^2)
    // SC - O(n)
    int minJumpsInDP(int arr[], int n) {
        // jumps[i] stores the minimum number of jumps needed to reach this index. jumps[0] = 0;
        int jumps[n];
        jumps[0] = 0;
        for(int i = 0; i < n; ++i) {
            jumps[i] = INT_MAX;
            for(int j = 0; j < n; ++j) {
                if(arr[j] + j >= i and jumps[j] != INT_MAX) {
                    jumps[i] = min(jumps[i], jumps[j] + 1);
                }
            }
        }
        return jumps[n - 1];

    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends