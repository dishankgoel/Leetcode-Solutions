class Solution {
public:
    static int compare(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    int lis(vector<vector<int>> v) {
        int n = v.size();
        int ans = 1;
        vector<vector<int>> dp = v;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < v[i].size(); j++) {
                dp[i][j] = 1;
                for(int k = 0; k < i; k++) {
                    for(int l = 0; l < v[k].size(); l++) {
                        if(v[i][j] > v[k][l]) {
                            dp[i][j] = max(dp[i][j], dp[k][l] + 1);
                        }
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0) {
            return 0;
        }
        int ans = 0;
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<vector<int>> sorted_box(n);
        int ptr = 0;
        sorted_box[ptr].push_back(envelopes[0][1]);
        for(int i = 1; i < n; i++) {
            if(envelopes[i][0] != envelopes[i - 1][0]) {
                ptr++;
            }
            sorted_box[ptr].push_back(envelopes[i][1]);
        }
        return lis(sorted_box);

    }
};