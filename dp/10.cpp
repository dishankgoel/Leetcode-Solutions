#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int dp[n+1][m+1];
        dp[0][0] = 1;
        if(p[0] == '*') {
            return false;
        }
        for(int i = 1; i < n + 1; i++) {
            dp[i][0] = 0;
        }
        for(int j = 1; j < m+1; j++) {
            if(p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }else {
                dp[0][j] = 0;    
            }
        }
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    char to_match = p[j-2];
                    dp[i][j] = dp[i][j-2];
                    int k = i-1;
                    while((k >= 0) && (to_match == '.' || to_match == s[k])) {
                        dp[i][j] = dp[i][j] || dp[k][j-2];
                        k--;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};