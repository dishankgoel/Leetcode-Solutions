#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<pair<int, int>>> maxDp1;
    vector<vector<pair<int, int>>> maxDp2;

    vector<int> MaxNumberSingleArray(vector<int> nums, int size, int t) {
        int n = nums.size();
        vector<int> ans;
        int curr_start = 0;
        for(int i = 0; i < size && curr_start <= n - size + i; i++) {
            if(t == 1) {
                ans.push_back(maxDp1[curr_start][n - size + i].first);
                curr_start = maxDp1[curr_start][n - size + i].second + 1;
            } else {
                ans.push_back(maxDp2[curr_start][n - size + i].first);
                curr_start = maxDp2[curr_start][n - size + i].second + 1;
            }
        }
        return ans;
    }

    int compare(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size(); 
        for(int i = 0; i < n; i++) {
            if(nums2[i] > nums1[i]) {
                return 2;
            } else if(nums1[i] > nums2[i]) {
                return 1;
            }
        }
        return 1;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> ans;
        auto s1 = nums1.begin(), e1 = nums1.end();
        auto s2 = nums2.begin(), e2 = nums2.end();
        while(s1 != e1 || s2 != e2) {
            ans.push_back(lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++);
        }
        return ans;
    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        maxDp1 = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, -1}));
        maxDp2 = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(m, {-1, -1}));
        for(int i = 0; i < n; i++) {
            maxDp1[i][i] = {nums1[i], i};
            for(int j = i + 1; j < n; j++) {
                if(nums1[j] > maxDp1[i][j - 1].first) {
                    maxDp1[i][j] = {nums1[j], j};
                } else {
                    maxDp1[i][j] = maxDp1[i][j - 1];
                }
            }
        }
        for(int i = 0; i < m; i++) {
            maxDp2[i][i] = {nums2[i], i};
            for(int j = i + 1; j < m; j++) {
                if(nums2[j] > maxDp2[i][j - 1].first) {
                    maxDp2[i][j] = {nums2[j], j};
                } else {
                    maxDp2[i][j] = maxDp2[i][j - 1];
                }
            }
        }
        vector<int> ans(k, -1);
        for(int pos_size = 0; pos_size < k + 1; pos_size++) {
            int sec_size = k - pos_size;
            vector<int> v1 = MaxNumberSingleArray(nums1, pos_size, 1);
            vector<int> v2 = MaxNumberSingleArray(nums2, sec_size, 2);
            vector<int> v = merge(v1, v2);
            if(v.size() == k) {
                if(compare(ans, v) == 2) {
                    ans = v;
                }
            }
            
        }

        return ans;

    }
};