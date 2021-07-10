#include<bits/stdc++.h>

using namespace std;



void kmp(string txt, string pat) {
    int i = 0, j = 0;
    int n = txt.length(), m = pat.length();
    int *lps = computeLps(pat);
    while(i < n) {
        if(pat[j] == txt[i]) {
            i++;
            j++;
        }
        if(j == m) {
            cout << "Found!";
            j = lps[j - 1];
        } else if(i < n and pat[j] != txt[i]) {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int* computeLps(string pat) {
    int m = pat.length();
    int lps[m];
    lps[0] = 0;
    int len = 0, i = 1;
    while(i < m) {
        if(pat[len] == pat[i]) {
            len++;
            lps[i] = len;
            i++; 
        }
        else {
            if(len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}