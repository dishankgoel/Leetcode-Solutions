#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        ll p = 1000000000 + 7;
        pair<ll, ll> dp[n][m];
        ll curr = 1;
        for(int i = 0; i < n; i++) {
            curr *= grid[i][0];
            dp[i][0] = make_pair(curr, curr);
        }
        curr = 1;
        for(int j = 0; j < m; j++) {
            curr *= grid[0][j];
            dp[0][j] = make_pair(curr, curr);
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                ll s1 = dp[i-1][j].first;
                ll s2 = dp[i][j-1].first;
                ll b1 = dp[i-1][j].second;
                ll b2 = dp[i][j-1].second;
                ll val1 = min(s1, s2)*grid[i][j];
                ll val2 = max(b1, b2)*grid[i][j];
                dp[i][j] = make_pair(min(val1, val2), max(val1, val2));
            }
        }
        return dp[n-1][m-1].second < 0 ? -1 : (dp[n-1][m-1].second)%p;
    }
};