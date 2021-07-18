class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int i = 0; i < n; i++) {
            total_sum += nums[i];
        }
        if(total_sum%2 == 1) {return 0;}

        int ans = 0;
        int dp[n + 1][total_sum + 1];

        for(int i = 0; i < total_sum + 1; i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; i++) {
            for(int pos_sum = 0; pos_sum < total_sum + 1; pos_sum++) {
                if(pos_sum - nums[i - 1] >= 0) {
                    dp[i][pos_sum] = dp[i - 1][pos_sum] | dp[i - 1][pos_sum - nums[i - 1]];
                } else {
                    dp[i][pos_sum] = dp[i - 1][pos_sum];
                }
            }
        }
        return dp[n][total_sum/2];
    }
};