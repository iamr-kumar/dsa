class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // DP soliton O(n^2) time and space
         string res = "";
        int maxLength = 1;
        bool dp[n][n];
        int start = 0;
        memset(dp, false, sizeof(dp));
        for(int i = 0; i < n; ++i) 
            dp[i][i] = true;
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                if(maxLength != 2) {
                    start = i;
                }
                maxLength = 2;
            }
        }
        // for length of substring
        for(int i = 3; i <= n; ++i) {
            // starting index
            for(int j = 0; j < n - i + 1; ++j) {
                // end index of the substring
                int k = j + i - 1;
                if(dp[j + 1][k - 1] && s[j] == s[k]) {
                    dp[j][k] = true;
                    if(i > maxLength) {
                        
                        start = j;
                        maxLength = i;
                    }
                }
            }
        }
        
        
        for(int i = start; i < start + maxLength; ++i) 
            res += s[i];
        return res;

        int maxLength = 0;
        
        // O(n^2) time and O(n) space (if length of result string considered)
//         for palindrome of odd length
        for(int mid = 0; mid < n; ++mid) {
            for(int len = 0; mid - len >= 0 and mid + len < n; len++) {
                if(s[mid + len] != s[mid - len]) {
                    break;
                }
                int thisLen = 2 * len + 1;
                if(thisLen > maxLength) {
                    res = s.substr(mid - len, thisLen);
                    maxLength = thisLen;
                }
            }
        }
//         for palindrome of even length
        for(int mid = 0; mid < n - 1; ++mid) {
            for(int len = 1; mid - len + 1 >=0 and mid + len < n; ++len) {
                if(s[mid - len + 1] != s[mid + len]) {
                    break;
                }
                int thisLen = 2 * len;
                if(thisLen > maxLength) {
                    res = s.substr(mid - len + 1, thisLen);
                    maxLength = thisLen;
                }
            }
        }
        return res;
    }
};