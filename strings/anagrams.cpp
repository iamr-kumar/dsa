// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

bool isAnagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

vector<vector<string>> Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    int n = string_list.size();
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> anagrams;
    for(int i = 0; i < n; ++i) {
       string s = string_list[i];
       sort(s.begin(), s.end());
       anagrams[s].push_back(string_list[i]);
    }
    for(auto it: anagrams) {
        ans.push_back(it.second);
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}