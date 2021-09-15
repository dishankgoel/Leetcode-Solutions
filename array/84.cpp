#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestwidth(vector<int> heights) {
        int n = heights.size();
        stack<pair<int, int>> S;
        vector<int> backward(n);
        backward[0] = 0;
        S.push({heights[0], 0});
        for(int i = 1; i < n; i++) {
            int curr_top = S.top().first;
            int a = heights[i];
            while(a <= curr_top) {
                S.pop();
                if(S.empty()) {
                    break;
                }
                curr_top = S.top().first;
            }
            if(S.empty()) {
                backward[i] = i;
            } else {
                backward[i] = i - S.top().second - 1;
            }
            S.push({a, i});
        }
        return backward;

    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> b = largestwidth(heights);
        vector<int> rev = heights;
        reverse(rev.begin(), rev.end());
        vector<int> f = largestwidth(rev);
        reverse(f.begin(), f.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, heights[i]*(1 + b[i] + f[i]));
        }
        return ans;
    }
};
