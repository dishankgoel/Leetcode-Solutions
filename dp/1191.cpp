class Solution {
public:
    pair<long long, int> kadane(vector<int> arr) {
        int n = arr.size();
        long long ans = 0;
        int dp[n + 1];
        dp[0] = 0;
        int last = 0;
        for(int i = 1; i < n + 1; i++) {
            if(dp[i-1] + arr[i-1] > arr[i-1]) {
                dp[i] = dp[i-1] + arr[i-1];
            } else {
                dp[i] = arr[i-1];
            }
            // ans = max(ans, dp[i]);
            if(dp[i] > ans) {
                ans = dp[i];
                last = i-1;
            }
        }
        return make_pair(ans, last);
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int p = 1000000000 + 7;
        int n = arr.size();
        vector<int> new_arr(arr);
        long long s = 0;
        for(auto i : arr) {
            new_arr.push_back(i);
            s += i;
        }
        int last1, last2;
        int ans1 = 0, ans2 = 0;
        pair<long long, int> a1, a2;
        a1 = kadane(arr);
        long long ans = 0;
        if(k >= 2) {
            a2 = kadane(new_arr); 
            if(a2.second >= n) {
                ans = max(ans, max(a2.first, a2.first + s*(long long)(k-2)));
            } else {
                ans = max(ans, a2.first);
            }
        } else {
            ans = max(ans, a1.first);
        }
        return ans%p;

    }
};