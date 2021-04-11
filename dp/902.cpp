#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll solve(vector<string> digits, string n, int samedig) {
        string s = n;
        int m = s.size();
        ll ans = 0;
        string curr = s.substr(0, 1);
        for(int i = 0; i < digits.size(); i++) {
            if(curr > digits[i]) {
                ans += pow(digits.size(), m - 1);
            } else if(curr == digits[i]) {
                if(m == 1) {
                    ans += 1;
                }else {
                    ans += solve(digits, s.substr(1, m - 1), 1);
                }
            }
        }
        if(s[0] != '0' && !samedig) {
            for(int i = m - 1; i > 0; i--) {
                ans += pow(digits.size(), i);
            }
        }
        
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        ll ans = 0;
        ans += solve(digits, s, 0);
        return ans;
    }
};
