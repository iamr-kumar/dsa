// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int size = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        for(int i = 0; i < size - 3; ++i) {
            for(int j = i + 1; j < size - 2; ++j) {
                int low = j + 1, high = size - 1;
                while(low < high) {
                    int sum = (arr[i] + arr[j] + arr[low] + arr[high]);
                    
                    if(sum == k) {
                       
                        answer.push_back({arr[i], arr[j], arr[low], arr[high]});
                        low++;
                        high--;
                    } else if(sum < k) {
                        low++;
                    } else {
                        high--;
                    }
                    
                }
            }
            
        }
        return answer;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}