class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(); int m = key.size();
        int dp[m + 1][n];
        for(int i = 0; i < n; i++) {
            dp[m][i] = 0;
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = 1e7;
                for(int pos_curr = 0; pos_curr < n; pos_curr++) {
                    if(ring[pos_curr] == key[i]) {
                        dp[i][j] = min(dp[i][j], min(abs(pos_curr - j), n - abs(pos_curr - j)) + dp[i + 1][pos_curr]);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};