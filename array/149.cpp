class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        vector<map<pair<int, int>, int>> dp(n);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int a = points[i][1] - points[j][1], b = points[i][0] - points[j][0];
                int gc = __gcd(abs(a), abs(b));
                a = a/gc;
                if(b < 0) {a = a*-1;}
                b = abs(b/gc);
                if(b == 0) {a = 1;}
                pair<int, int> slope = {a, b};
                dp[i][slope] = max(dp[i][slope], dp[j][slope] + 1);
                ans = max(ans, dp[i][slope]);
            }
        }
        return ans + 1;

    }
};
