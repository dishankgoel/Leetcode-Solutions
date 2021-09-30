#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int forward[n];
        int backward[n];
        forward[0] = nums[0]; backward[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            if(i%k == 0) {
                forward[i] = nums[i];
            } else {
                forward[i] = max(forward[i - 1], nums[i]);
            }
            int j = n - i - 1;
            if(j%k == k - 1) {
                backward[j] = nums[j];
            } else {
                backward[j] = max(backward[j + 1], nums[j]);
            }
        }
        for(int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            ans.push_back(max(forward[j], backward[i]));
        }
        return ans;

    }

};
