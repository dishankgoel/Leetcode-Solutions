class Solution {
public:
    int hash(char s) {
        if(s >= 'a') {
            return s - 'a';
        } else {
            return s - 'A' + 26;
        }
    }
    string minWindow(string s, string t) {
        vector<int> reqwindow(26*2, 0);
        for(int i = 0; i < t.size(); i++) {
            reqwindow[hash(t[i])]++;
        }
        int i = 1, j = 0;
        vector<int> currwindow(26*2, 0);
        currwindow[hash(s[0])]++;
        int minstart = 0, minend = s.size() + 1;
        while(i < s.size() + 1 && j < i) {
            // Check if statisfied
            int statisfied = 1;
            for(int p = 0; p < 26*2; p++) {
                if(currwindow[p] < reqwindow[p]) {
                    statisfied = 0;
                    break;
                }
            }
            if(statisfied) {
                cout<<i<<" "<<j<<"\n";
                if(minend - minstart > i - j) {
                    minend = i;
                    minstart = j;
                }
                currwindow[hash(s[j])]--;
                j++;
            } else {
                if(i < s.size()) {
                    currwindow[hash(s[i])]++;
                }
                i++;
            }
        }
        string ans = "";
        if(minend - minstart   <= s.size()) {
            ans = s.substr(minstart, minend - minstart);
        }
        return ans;
    }
};
