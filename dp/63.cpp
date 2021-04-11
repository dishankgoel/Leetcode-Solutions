#define ll long long
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();   
        if(n == 0) {return 0;}
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ob1 = 0, ob2 = 0;
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[i][0] == 1) {
                ob1 = 1;
            }
            if(ob1) {
                dp[i][0] = -1;
            } else {
                dp[i][0] = 1;
            }
        }
        for(int j = 0; j < m; j++) {
            if(obstacleGrid[0][j] == 1) {
                ob2 = 1;
            }
            if(ob2) {
                dp[0][j] = -1;
            } else {
                dp[0][j] = 1;
            }
        }
        for(int i = 1; i < n ; i++) {
            for(int j = 1; j < m ; j++) {
                if(obstacleGrid[i][j] == 0) {
                    if(dp[i-1][j] != -1) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if(dp[i][j-1] != -1) {
                        dp[i][j] += dp[i][j-1];
                    }
                } else {
                    dp[i][j] = -1;
                }
            }
        }
        return dp[n - 1][m - 1] == -1 ? 0 : dp[n - 1][m - 1];
    }
};