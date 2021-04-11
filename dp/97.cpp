class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        int dp[n + 1][m + 1][k + 1];
        dp[0][0][0] = 1;
        for(int i = 1; i < n + 1; i++) {
            dp[i][0][0] = 0;
        }
        for(int j = 1; j < m + 1; j++) {
            dp[0][j][0] = 0;
        }
        for(int p = 1; p < k + 1; p++) {
            dp[0][0][p] = 0;
        }
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                dp[i][j][0] = 0;
            }
        }
        for(int i = 1; i < n + 1; i++) {
            for(int p = 1; p < k + 1; p++) {
                if(s1[i - 1] == s3[p - 1]) {
                    dp[i][0][p] = dp[i - 1][0][p - 1];
                } else {
                    dp[i][0][p] = 0;
                }
            }
        }
        for(int j = 1; j < m + 1; j++) {
            for(int p = 1; p < k + 1; p++) {
                if(s2[j - 1] == s3[p - 1]) {
                    dp[0][j][p] = dp[0][j - 1][p - 1];
                } else {
                    dp[0][j][p] = 0;
                }
            }
        }
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                for(int p = 1; p < k + 1; p++) {
                    if(s3[p - 1] == s1[i - 1] && s3[p - 1] == s2[j - 1]) {
                        dp[i][j][p] = dp[i - 1][j][p - 1] || dp[i][j - 1][p - 1];
                    } else if (s3[p - 1] == s1[i - 1]) {
                        dp[i][j][p] = dp[i - 1][j][p - 1];
                    } else if(s3[p - 1] == s2[j - 1]) {
                        dp[i][j][p] = dp[i][j - 1][p - 1];
                    } else {
                        dp[i][j][p] = 0;
                    }
                }
            }
        }
        return dp[n][m][k];
    }
};