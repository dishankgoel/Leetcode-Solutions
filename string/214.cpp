#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(); string str = s;
        if(n == 1 || n == 0){return s;}
        string rev = s; reverse(rev.begin(), rev.end());
        s += "$" + rev;
        int m = s.size();
        int lps[m];
        lps[0] = 0;
        int j = 0;
        for(int i = 1; i < m; ) {
            if(s[j] == s[i]) {
                lps[i] = j+1;j++; i++;
            } else {
                if(j == 0) {
                    lps[i] = 0; i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        string extra = str.substr(lps[m - 1], n - lps[m - 1]);
        reverse(extra.begin(), extra.end()); 
        return extra + str;

    }
};
