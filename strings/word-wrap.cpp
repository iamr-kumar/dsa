// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        int cost[n + 1][n + 1];
        int extra[n + 1][n + 1];
        // first find the extra space that will be left if words from i to j are placed in a line
        for(int i = 1; i <= n; ++i) {
            extra[i][i] = k - nums[i - 1];
            for(int j = i + 1; j <= n; ++j) {
                extra[i][j] = extra[i][j - 1] - nums[j - 1] - 1;
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                if(extra[i][j] < 0) {
                    cost[i][j] = INT_MAX;
                } else if(j == n and extra[i][j] >= 0) {   // condition to check for the last
                // word as no space is left for the last word
                    cost[i][j] = 0;
                } 
                else {
                    cost[i][j] = extra[i][j] * extra[i][j];
                }
            } 
        }
        
        // this stores the minCose to arrange words from 1 to j in different lines.
        int minCost[n + 1];
        minCost[0] = 0;  // no cost to arrange 0 word
        for(int j = 1; j <= n; ++j) {
            minCost[j] = INT_MAX;
            for(int i = 1; i <= j; ++i) {
                // check if it is possible to arrange words from 1 to i - 1 in the prveious lines and words from i to j in 
                // the current line and the cost for that is less than the current cost.
                if(minCost[i - 1] != INT_MAX and cost[i][j] != INT_MAX and minCost[j] > minCost[i - 1] + cost[i][j]) {
                    minCost[j] = minCost[i - 1] + cost[i][j];
                }
            }
        }
        return minCost[n];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends