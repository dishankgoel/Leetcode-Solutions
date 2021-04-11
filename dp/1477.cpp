class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> m;
        m[0] = -1;
        m[arr[0]] = 0;
        int s = arr[0];
        vector<int> dp(n, INT_MAX);
        int min_len = INT_MAX;
        if(s == target) {
            dp[0] = 1;
        }
        for(int i = 1; i < n; i++) {
            s += arr[i];
            int req = s - target;
            if(m.find(req) != m.end()) {
                int start_pos = m[req] + 1;
                int l = i - start_pos + 1;
                dp[i] = min(dp[i - 1], l);
                if(start_pos >= 1) {
                    int second_one = dp[start_pos - 1];
                    if(second_one != INT_MAX) {
                        min_len = min(min_len, l + second_one);
                    }
                }
                
            } else {
                dp[i] = dp[i-1];
            }
            m[s] = i;
        }
        return min_len == INT_MAX ? -1 : min_len;

    }
};