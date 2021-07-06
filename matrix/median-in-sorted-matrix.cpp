// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here        
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < r; ++i) {
            mx = max(matrix[i][0], mx); 
            mn = min(matrix[i][c - 1], mn);
        }
        int req = (r * c + 1) / 2;
        while(mn < mx) {
            int mid = mn + (mx - mn) / 2;
            int small = 0;
            for(int i = 0; i < r; ++i) {
                small += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(small < req) {
                mn = mid + 1;
            } else {
                mx = mid;
            }
        }
        return mn;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
} 