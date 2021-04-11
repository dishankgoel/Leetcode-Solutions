#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Problem in merge
    // If the elements are same, then we cannot decide which one to take
    vector<int> merge(vector<int> v1, vector<int> v2) {
        int n = v1.size();
        int m = v2.size();
        vector<int> v;
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < n && ptr2 < m) {
            if(v1[ptr1] > v2[ptr2]) {
                v.push_back(v1[ptr1]);
                ptr1++;
            }else if(v1[ptr1] < v2[ptr2]) {
                v.push_back(v2[ptr2]);
                ptr2++;
            }else {
                if(ptr1 < n - 1 && ptr2 < m - 1) {
                    if(v1[ptr1 + 1] > v2[ptr2 + 1]) {
                        v.push_back(v1[ptr1]);
                        ptr1++;
                    }else {
                        v.push_back(v2[ptr2]);
                        ptr2++;
                    }
                } else if(ptr1 < n - 1) {
                    v.push_back(v1[ptr1]);
                    ptr1++;
                } else if(ptr2 < m - 1) {
                    v.push_back(v2[ptr2]);
                    ptr2++;
                } else {
                    v.push_back(v1[ptr1]);
                    ptr1++;
                }
            }
        }
        while(ptr1 < n) {
            v.push_back(v1[ptr1]);
            ptr1++;
        }
        while(ptr2 < m) {
            v.push_back(v2[ptr2]);
            ptr2++;
        }
        return v;
    }
    int comp(vector<int> v1, vector<int> v2) {
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] > v2[i]) {
                return 1;
            } else if(v1[i] < v2[i]) {
                return -1;
            }
        }
        return 0;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp1(n+1, vector<int>());
        vector<vector<int>> dp1_next(n+1, vector<int>());
        for(int i = 0; i < n; i++) {
            for(int cnt = 1; cnt <= min(n, i + 1); cnt++) {
                dp1_next[cnt] = dp1[cnt - 1];
                if(dp1[cnt].empty()) {
                    dp1_next[cnt].push_back(nums1[i]);
                }else {
                    vector<int> v = dp1[cnt - 1];
                    v.push_back(nums1[i]);
                    if(comp(v, dp1[cnt]) == -1) {
                        dp1_next[cnt] = dp1[cnt];
                    }else {
                        dp1_next[cnt].push_back(nums1[i]);
                    }
                }
            }
            dp1 = dp1_next;
        }
        vector<vector<int>> dp2(m+1, vector<int>());
        vector<vector<int>> dp2_next(m+1, vector<int> ());
        for(int i = 0; i < m; i++) {
            for(int cnt = 1; cnt <= min(m, i + 1); cnt++) {
                dp2_next[cnt] = dp2[cnt - 1];
                if(dp2[cnt].empty()) {
                    dp2_next[cnt].push_back(nums2[i]);
                }else {
                    vector<int> v = dp2[cnt - 1];
                    v.push_back(nums2[i]);
                    if(comp(v, dp2[cnt]) == -1) {
                        dp2_next[cnt] = dp2[cnt];
                    }else {
                        dp2_next[cnt].push_back(nums2[i]);
                    }
                }
            }
            dp2 = dp2_next;
        }
        vector<int> ans(k, 0);
        for(int i = 0; i <= min(k, n); i++) {
            if(k - i <= m) {
                vector<int> v = merge(dp1[i], dp2[k - i]);
                int r = comp(ans, v);
                if(r == -1) {
                    ans = v;
                }
            }
        }
        return ans;

    }
};