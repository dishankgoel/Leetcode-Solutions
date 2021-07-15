#define ll long long

ll p = 1e9 + 7;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) {
            return 0;
        }
        ll dp[n][m][maxMove];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { 
                dp[i][j][0] = 0;
            }
        }
        dp[startColumn][startRow][0] = 1;
        for(int move = 1; move < maxMove; move++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    dp[i][j][move] = 0;
                    if(j > 0) {
                        dp[i][j][move] = (dp[i][j][move] + dp[i][j - 1][move - 1])%p;
                    }
                    if(j < m - 1) {
                        dp[i][j][move] = (dp[i][j][move] + dp[i][j + 1][move - 1])%p;
                    }
                    if(i > 0) {
                        dp[i][j][move] = (dp[i][j][move] + dp[i - 1][j][move - 1])%p;
                    }
                    if(i < n - 1) {
                        dp[i][j][move] = (dp[i][j][move] + dp[i + 1][j][move - 1])%p;
                    }    
                }
            }
        }
        ll ans = 0;
        for(int move = 0; move < maxMove; move++) {
            for(int j = 1; j < m - 1; j++) {
                ans = (ans + dp[0][j][move])%p;
                ans = (ans + dp[n - 1][j][move])%p;
            }
            for(int i = 1; i < n - 1; i++) {
                ans = (ans + dp[i][0][move])%p;
                ans = (ans + dp[i][m - 1][move])%p;
            }
            if(n == 1) {
                if(m == 1) {
                    ans = (ans + (4*dp[0][0][move]))%p;
                } else {
                    ans = (ans + (3*dp[0][0][move])%p)%p;
                    ans = (ans + (3*dp[0][m - 1][move])%p)%p;
                }
            } else {
                if(m == 1) {
                    ans = (ans + (3*dp[0][0][move])%p)%p;
                    ans = (ans + (3*dp[n - 1][0][move])%p)%p;
                } else {
                    ans = (ans + (2*dp[0][0][move])%p)%p;
                    ans = (ans + (2*dp[0][m - 1][move])%p)%p;
                    ans = (ans + (2*dp[n - 1][0][move])%p)%p;
                    ans = (ans + (2*dp[n - 1][m - 1][move])%p)%p;
                }
            }

        }
        return ans;
    }
};