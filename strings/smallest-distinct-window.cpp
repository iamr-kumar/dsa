// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        int n = str.length();
        bool visited[256] = {false};
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[str[i]]) {
                visited[str[i]] = true;
                count++;
            }
        }
        int start = 0, startIndex = -1, minCount = INT_MAX;
        int charCount[256] = {0};
        int distCount = 0;
        for(int j = 0; j < n; ++j) {
            charCount[str[j]]++;
            if(charCount[str[j]] == 1) {
                distCount++;
            }
            if(distCount == count) {
                while(charCount[str[start]] > 1) {
                    if(charCount[str[start]] > 1)
                        charCount[str[start]]--;
                    start++;
                }
                int len = j - start + 1;
    
                if(len < minCount) {
                    startIndex = start;
                    minCount = len;
                }
            }
        }
        
        return str.substr(startIndex, minCount);
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
} 