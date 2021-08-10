#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxchoose;
    int total;
    unordered_map<int, int> dp;
    int solve(int state, int currtotal) {
        int ans = 0;
        if(dp.find(state) != dp.end()) {
            return dp[state];
        }
        if(currtotal >= total) {
            return 0;
        }
        for(int j = 0; j < maxchoose; j++) {
            if((state&(1<<j)) == 0) {
                ans = (ans || !solve(state | (1 << j), currtotal + j + 1));
            }
        }
        dp[state] = ans;
        return ans;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxchoose = maxChoosableInteger; total = desiredTotal;
        if(total == 0) {return 1;}
        if(total > (maxchoose*(maxchoose + 1)/2)) {return 0;}
        return solve(0, 0);
    }
};