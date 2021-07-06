#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isVowel(char k) {
        char c = tolower(k);
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c== 'u')
             return true;
        return false;
    }
    string reverseVowels(string s) {
        stack<char> vowels;
        string res;
        for(char c: s) {
            if(isVowel(c))
                vowels.push(c);
        }
        for(char c: s) {
            if(isVowel(c)) {
                res += vowels.top();
                vowels.pop();
            } else {
                res += c;
            }
            
        }
        return res;
        
    }
};