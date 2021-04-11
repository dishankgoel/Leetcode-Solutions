#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) {
            return 0;
        }
        unordered_map<int, int> m;
        int curr_sum = 0;
        int new_sum;
        int ans = 0;
        for(int i = 0; i <= n - 2; i++) {
            if(k == 0) {
                m[curr_sum] = 1;  
                new_sum = (curr_sum + nums[i] + nums[i+1]);
            } else {
                m[curr_sum%k] = 1;
                new_sum = (curr_sum + nums[i] + nums[i+1])%k;
            }
            if(m.find(new_sum) != m.end()) {
                ans = 1;
                break;
            }
            curr_sum += nums[i];
        }
        return ans; 
    }
};