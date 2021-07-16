#define LOG_DEPTH 20
#define ll long long

class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp = vector<vector<int>>(n, vector<int>(LOG_DEPTH + 1, -1));
        for(int d = 0; d < LOG_DEPTH + 1; d++) { 
            for(int i = 0; i < n; i++) {
                if(d == 0) {
                    dp[i][d] = parent[i];
                } else {
                    if(dp[i][d - 1] == -1) {
                        dp[i][d] = -1;
                    } else {
                        dp[i][d] = dp[dp[i][d - 1]][d - 1];
                    }
                }
            }
        }
    }
    int getKthAncestor(int node, int k) {
        int ans = node;
        int curr_depth = 0;
        while((1 << curr_depth) <= k) {
            ll jump = (1 << curr_depth) & k;
            if(jump) {
                ans = dp[ans][curr_depth];
            }
            if(ans == -1) {
                break;
            }
            curr_depth = curr_depth + 1; 
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */