#define ll long long

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(auto a : nums) {total_sum += a;}
        ll dp[n + 1][total_sum + 1];
        for(int pos_sum = 0; pos_sum < total_sum + 1; pos_sum++) {
            dp[0][pos_sum] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; i++) {
            for(int pos_sum = 0; pos_sum < total_sum + 1; pos_sum++) {
                if(pos_sum - nums[i - 1] >= 0) {
                    if(dp[i - 1][pos_sum - nums[i - 1]] > 0) {
                        ll curr = dp[i - 1][pos_sum];
                        curr = curr | (dp[i - 1][pos_sum - nums[i - 1]] << 1);
                        dp[i][pos_sum] = curr;
                    } else {
                        dp[i][pos_sum] = dp[i - 1][pos_sum];
                    }
                } else {
                    dp[i][pos_sum] = dp[i - 1][pos_sum];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < total_sum + 1; i++) {
            for(int j = 1; j < n; j++) {
                if(dp[n][i]&(1<<j)) {
                    if(i*(n - j) == (total_sum - i)*j) {
                        ans = 1;
                    }
                }
            }
        }
        return ans;

    }
};