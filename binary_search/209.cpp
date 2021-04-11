#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        vector<int> presum(n);
        presum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            presum[i] = presum[i-1] + nums[i];
        }
        int ans = INT_MAX;
        int b = 1, e = n;
        while(b <= e) {
            int mid = b + (e - b)/2;
            int found = 0;
            for(int i = mid - 1; i < n; i++) {
                int start = i - mid + 1;
                int val = start == 0 ? presum[i] : presum[i] - presum[start - 1];
                if(val >= s) {
                    found = 1;
                    ans = min(ans, mid);
                    break;
                }
            }
            if(found) {
                e = mid - 1;
            } else {
                b = mid + 1;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};