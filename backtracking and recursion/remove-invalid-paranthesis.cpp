/*
Ref: https://www.geeksforgeeks.org/remove-invalid-parentheses/

An expression will be given which can contain open and close parentheses and optionally some characters, No other operator will be there in string. We need to remove minimum number of parentheses to make the input string valid. If more than one valid output are possible removing same number of parentheses then print all such output.

For generating all possible outputs, backtracking is used
Remove a bracket and check if the string is valid or not.
If not valid, put back the bracket and check for other oprtions.
To find the least number of removals, BFS for each string is used.

*/

#include<bits/stdc++.h>

using namespace std;

// Function to check if a string is valid or nor
bool isValid(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '(') {
            count++;
        }
        else if(s[i] == ')') {
            count--;
        }
        if(count < 0) {
            return false;
        }
    }
    if(count == 0) {
        return true;
    }
}

void solve(string s) {
    // Set to keep track of already checked strings
    set<string> visited;
    queue<string> q;
    visited.insert(s);
    q.push(s);
    bool flag = false;
    while(!q.empty()) {
        string str = q.front();
        q.pop();
        if(isValid(str)) {
            cout << str << "\n";
            flag = true;
        }
        if(flag) {
            continue;
        }
        for(int i = 0; i < str.length(); ++i) {
            if(str[i] == ')' or str[i] == '(') {
                // Remove this parenthesis and make a temp string
                string temp = str.substr(0, i) + str.substr(i + 1);
                // Check if this string has already been visited
                if(visited.find(temp) == visited.end()) {
                    visited.insert(temp);
                    q.push(temp);
                }
            }
            else {
                continue;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
// Function call
    solve(s);
    return 0;
}