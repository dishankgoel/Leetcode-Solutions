#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
public:
    string decs(string s) {
        int n = s.size();
        string ans = s;
        int carry = 1, curr = n - 1;
        while(carry && curr >= 0) {
            if(s[curr] != '0') {
                ans[curr] = s[curr] - 1;
                carry = 0;
            } else {
                ans[curr] = '9';
            }
            curr--;
        }
        return ans;
    }

    string incs(string s) {
        int n = s.size();
        string ans = s;
        int carry = 1, curr = n - 1;
        while(carry && curr >= 0) {
            if(s[curr] != '9') {
                ans[curr] = s[curr] + 1;
                carry = 0;
            } else {
                ans[curr] = '0';
            }
            curr--;
        }
        return ans;
    }

    string rev(string s, int l, int r) {
        string ans;
        for(int i = r; i >= l; i--) {
            ans.push_back(s[i]);
        }
        return ans;
    }

    double s_to_d(string s) {
        double ans = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            ans += (s[i] - '0')*pow(10, (n - 1 - i));
        }
        return ans;
    }

    string nearestPalindromic(string n) {
        
        int len = n.size();
        string fhalf = n.substr(0, (len+1)/2);
        string s1 = decs(fhalf);
        string s2 = incs(fhalf);
        string s3 = fhalf;
        if(len%2 == 0) {
            s1 += rev(s1, 0, s1.size() - 1);
            s2 += rev(s2, 0, s2.size() - 1);
            s3 += rev(s3, 0, s3.size() - 1);
        } else {
            s1 += rev(s1, 0, s1.size() - 2);
            s2 += rev(s2, 0, s2.size() - 2);
            s3 += rev(s3, 0, s3.size() - 2);
        }
        if(s1.size() != 1 && s1[s1.size() - 1] == '0') {
            s1.erase(0, 1);
            s1[s1.size() - 1] = '9';
        }
        if(s2[0] == '0') {
            s2.insert(s2.begin(), '1');
            s2[s2.size() - 1] = '1';
        }
        // cout<<s1<<" "<<s2<<" "<<s3;
        double diff = 1e19;
        diff = abs(s_to_d(n) - s_to_d(s1));
        string ans = s1;
        double new_diff = abs(s_to_d(n) - s_to_d(s3));
        if(new_diff < diff && n != s3) {
            ans = s3;
            diff = new_diff;
        }
        if(abs(s_to_d(n) - s_to_d(s2)) < diff) {
            ans = s2;
        }
        return ans;
    }
};

// int main() {
//     Solution s1;
//     string a; cin>>a;
//     string m = s1.nearestPalindromic(a);
// }