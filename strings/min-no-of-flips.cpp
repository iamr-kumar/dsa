// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int n = s.length();
    int even = 0, odd = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0' and i & 1) 
            odd++;
        else if(s[i] == '0')
            even++;
    }
    int count = 0;
    if(odd >= even) {
        for(int i = 0; i < n; ++i) {
            if(i & 1 and s[i] == '1')
                count++;
            if(!(i & 1) and s[i] == '0')
                count++;
        }
    } else {
        for(int i = 0; i < n; ++i) {
            if(i & 1 and s[i] == '0')
                count++;
            if(!(i & 1) and s[i] == '1')
                count++;
        }
    }
    return count;
}