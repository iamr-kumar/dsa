
#include <bits/stdc++.h>

using namespace std;

bool isRotation(string s1, string s2) {
    if(s1.length() != s2.length()) 
        return false;
    string temp = s1 + s1;
    // now check if s2 is a substring of temp:
    // yes -> s2 is rotation of s1
    // no -> not rotation

    return (temp.find(s2) != string::npos);
}