#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(int limit, vector<int> bits, int curr_total, bool turn) {
        int n = bits.size();
        bool ans = false; 
        for(int i = 0; i < n; i++) {
            if(bits[i] != 1) {
                vector<int> new_bits(bits);
                new_bits[i] = 1;
                int new_total = curr_total + (i + 1);
                if(new_total >= limit) {
                    ans = ans || true;
                }else {
                    if(turn) {
                        ans = ans || !solve(limit, bits, new_total, !turn);
                    } else {
                        ans = ans || solve(limit, bits, new_total, !turn);
                    }
                    
                }
            }
        }
        return ans;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<int> bits(maxChoosableInteger, 0);
        return solve(desiredTotal, bits, 0, true);
    }
};