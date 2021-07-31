#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isDecimal(string s, int l, int r) {
        int n = s.size();
        if(l < 0 || l >= n || r < 0 || r >= n || l > r) {
            return 0;
        }
        if(s[l] == '+' || s[l] == '-') {
            l++;
        }
        if(l > r) {
            return 0;
        }
        int c = 0, dotpos = -1;
        for(int i = l; i <= r; i++) {
            if(s[i] == '.') {
                dotpos = i;
                c++;
            }
        }
        if(c != 1) {return 0;}
        int fdig = 0;
        for(int i = l; i <= dotpos - 1; i++) {
            if(('0' <= s[i] && s[i] <= '9')) {
                fdig++;
            } else {
                return 0;
            }
        }
        int sdig = 0;
        for(int i = dotpos + 1; i <= r; i++) {
            if(('0' <= s[i] && s[i] <= '9')) {
                sdig++;
            } else {
                return 0;
            }
        }
        if(fdig == 0 && sdig == 0) {
            return 0;
        }
        return 1;
    }

    bool isInteger(string s, int l, int r) {
        int n = s.size();
        if(l < 0 || l >= n || r < 0 || r >= n || l > r) {
            return 0;
        }
        if(s[l] == '+' || s[l] == '-') {
            l++;
        }
        if(l > r) {
            return 0;
        }
        for(int i = l; i <= r; i++) {
            if(!(('0' <= s[i] && s[i] <= '9'))) {
                return 0;
            }
        }
        return 1;
    }


    bool isNumber(string s) {
        int n = s.size();
        int epos = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'e' || s[i] == 'E') {
                epos = i;break;
            }
        }
        if(epos == -1) {
            return isDecimal(s, 0, n - 1) || isInteger(s, 0, n - 1);
        }
        return (isDecimal(s, 0, epos - 1) || isInteger(s, 0, epos - 1))&&isInteger(s, epos + 1, n - 1);
    }
};