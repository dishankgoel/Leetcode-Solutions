#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(string s) {
        int n = s.size();
        int ans = n == 0 ? 0 : 1;
        int curr_count = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                curr_count++;
            } else {
                if(curr_count != 1) {
                    curr_count = 1;
                    ans += 1 + to_string(curr_count).size();    
                } else {
                    ans++;
                }
            }
        }
        if(curr_count != 1) {
            ans += 1 + to_string(curr_count).size();
        } else {
            ans++;
        }
        return ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n + 1][k + 1];
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < k + 1; j++) {
                dp[i][j];
            }
        }
    }
}