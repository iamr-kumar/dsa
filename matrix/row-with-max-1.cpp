#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int firstOne(vector<int> arr, int low, int high) {
        if(high >= low) {
            int mid = low + (high - low) / 2;
            if((mid == 0 || arr[mid - 1] == 0) and arr[mid] == 1) {
                return mid;
            }
            else if(arr[mid] == 0) {
                return firstOne(arr, mid + 1, high);
            } else {
                return firstOne(arr, low, mid - 1);
            }
        }
        return -1;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int max = 0, index = -1;
	    for(int i = 0; i < n; ++i) {
	        int k = firstOne(arr[i], 0, m - 1);
	        if(k != -1 and m - k > max) {
	            index = i;
	            max = m - k;
	        } 
	    }
	    return index;

      //second approach

       int max = 0, index = 0;
	    int j = m - 1;
	    for(int i = 0; i < n; ++i) {
	       bool flag = false;
	       while(j >= 0 and arr[i][j] == 1) {
	           j--;
	           flag = true;
	       }
	       if(flag) {
	           index = i;
	       }
	   
	    }
	    if(index == 0 and arr[0][m - 1] == 0) return -1;
	    return index;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends