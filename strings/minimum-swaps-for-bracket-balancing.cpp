// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int n = s.size();
        int left = 0, right = 0, ans = 0, swap = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '[') {
                left++;
                if(swap > 0) {
                    ans += swap;
                    swap--;
                }
            } else {
                right++;
                swap = right - left;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   