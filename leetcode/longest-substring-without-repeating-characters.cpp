#include<bits/stdc++.h>

using namespace std;

// Problem Statement - Given a string s, find the length of the longest substring without repeating characters.

// O(n^2) solution by sliding window technique
// As we travers through each substring, keep a visited array for each letter
// If the current letter is visited, break, else keep taking more letters in from the right
// After a substring is done, remove the first letter from left and repeat.
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            vector<bool> visited(256);
            for(int j = i; j < n; ++j) {
                if(visited[s[i]] == true) break;
                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
            visited[s[i]] = false;
        }
        return res;
    }
};

// linear time solution by storing the last index of the letters.
// We keep the starting index as 0. As we traverse, we check if the last index of the current letter is more than 
// or equal to this starting index or not. If yes, we reset the start index to lastIndex + 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.length();
        int start = 0;
        vector<int> lastIndex(256, -1);
        for(int j = 0; j < n; ++j) {
            start = max(lastIndex[s[j]] + 1, start);
            res = max(res, j - start + 1);
            lastIndex[s[j]] = j;
        }
        return res;
    }
};