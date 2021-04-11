#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        ll dp[n+1][n+1];
        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < n + 1; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = startFuel;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(dp[i][j] != -1) {
                    ll fuel = dp[i][j];
                    fuel -= i == 0 ? stations[0][0] : (stations[i][0] - stations[i - 1][0]);
                    if(fuel >= 0) {
                        dp[i+1][j] = max(dp[i+1][j], fuel);
                        dp[i+1][j+1] = max(dp[i+1][j+1], fuel + stations[i][1]);
                    } 
                }
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n + 1; j++) {
            if(n == 0) {
                if(startFuel - target >= 0) {
                    ans = 0;
                }
            } else {
                if(dp[n][j] >= 0 && dp[n][j] - (target - stations[n-1][0]) >= 0) {
                    ans = min(ans, j);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};