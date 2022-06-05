#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check_balanced(string s) {
        int count = 0;
        for(auto a : s) {
            if(a == '(') {
                count++;
            } else {
                count--;
            }
            if(count < 0) {
                return false;
            }
        }
        if(count != 0) {
            return false;
        }
        return true;
    }
    vector<string> generateParenthesis(int n) {
        if(n == 1) {
            return {"()"};
        }
        vector<string> known = generateParenthesis(n - 1);
        unordered_set<string> ans;
        for(auto val : known) {
            string new_element;
            for(int i = 0; i < val.length() + 1; i++) {
                if(i == val.length()) {
                    new_element = val.substr(0, i) + '(';
                } else {
                    new_element = val.substr(0, i) + '(' + val.substr(i, val.length() - i);
                }
                for(int j = 0; j < new_element.length() + 1; j++) {
                    string nel;
                    if(j == new_element.length()) {
                        nel = new_element.substr(0, j) + ')';
                    } else {
                        nel = new_element.substr(0, j) + ')' + new_element.substr(j, new_element.length() - j);
                    }
                    if(check_balanced(nel)) {
                        // cout<<nel<<"\n";
                        ans.insert(nel);
                    }
                }
            }
        }
        vector<string> final_ans;
        for(auto a : ans) {
            final_ans.push_back(a);
        }
        return final_ans;
    }
};

/* int main() {
    Solution s;
    for(auto a : s.generateParenthesis(3)) {
        cout << a << "\n";
    }
} */
