// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(char c: x) {
            if(c == '{' or c == '(' or c == '[') {
                s.push(c);
                continue;
            } 
            if(s.empty())
                return false;
            switch(c) {
                char k;
                case ')':
                    k = s.top();
                    s.pop();
                    if(k == '[' or k == '{') 
                        return false;
                    break;
                case '}':
                     k = s.top();
                    s.pop();
                    if(k == '(' or k == '[') 
                        return false;
                    break;
                case ']':
                     k = s.top();
                    s.pop();
                    if(k == '(' or k == '{') 
                        return false;
                    break;
                
                
            }
        }
        return (s.empty());
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}