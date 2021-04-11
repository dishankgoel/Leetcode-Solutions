#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) {return "";}
        int dp[n][n];
        int max_len = 1;
        int max_i = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        for(int size = 1; size < n; size++) {
            for(int i = 0; i + size < n; i++) {
                if(dp[i + 1][i + size - 1] == 1 && s[i] == s[i + size]) {
                    dp[i][i + size] = 1;
                    if(size + 1 > max_len) {
                        max_i = i;
                        max_len = size + 1;
                    }
                }
            }
        }
        string ans(s.substr(max_i, max_len));
        return ans;
        
    }
};