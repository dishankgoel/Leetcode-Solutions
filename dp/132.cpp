#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int if_palindrome[n+1][n+1];
        for(int i = 1; i < n + 1; i++) {
            if_palindrome[i][i] = 1;
        }
        for(int size = 1; size < n; size++) {
            for(int i = 1; i + size < n + 1; i++) {
                if(s[i-1] == s[i + size -1]) {
                    if(size == 1) {
                        if_palindrome[i][i + size] = 1;
                    }else {
                        if_palindrome[i][i + size] = if_palindrome[i+1][i + size -1];
                    } 
                }else {
                    if_palindrome[i][i + size] = 0;
                }
            }
        }
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            dp[i] = i;
            for(int j = i; j > 0; j--) {
                if(if_palindrome[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] - 1;
    }
};