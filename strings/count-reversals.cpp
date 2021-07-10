// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n = s.length();
    if(n & 1)
        return -1;
    int open = 0, close = 0;
    for(char c: s) {
        if(c == '{') {
            open++;
        } else {
            if(open == 0) {
                close++;
            } else {
                open--;
            }
        }
    }
   
    int ans = ceil(open / 2.0) + ceil(close / 2.0);
    return ans;
    
}