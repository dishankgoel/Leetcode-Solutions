#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;        
        for(int i = 1; i < n; i++) {
            if(s[i - 1] == '0') {continue;}
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] += dp[i-1];
                dp[i+1] += dp[i-1];
            } else {
                dp[i] += dp[i-1];
            }
        }
        if(n >= 1 && s[n-1] != '0') {
            dp[n] += dp[n-1];
        }
        return dp[n];
        
    }
};