#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans;
    vector<vector<int>> G;
    int n, m;
    int total_len;
    int endx, endy;
    int valid(int i, int j) {
        if(i >= 0 && i < n && j >= 0 && j < m) {
            if(G[i][j] == -1) {
                return 0;
            }
            return 1;
        }
        return 0;
    }
    void dfs(int i, int j, int curr_len, map<pair<int, int>, int> seen) {
        if(valid(i, j) == 0) {
            return;
        }
        cout<<i<<" "<<j<<"\n";
        if(seen.find(make_pair(i, j)) != seen.end()) {
            return;
        }
        if(i == endx && j == endy) {
            if(curr_len == total_len + 1) {
                ans++;
            }
        } else {
            map<pair<int, int>, int> new_seen = seen;
            new_seen[make_pair(i, j)] = 1;
            dfs(i, j + 1, curr_len + 1, new_seen);
            dfs(i, j - 1, curr_len + 1, new_seen);
            dfs(i + 1, j, curr_len + 1, new_seen);
            dfs(i - 1, j, curr_len + 1, new_seen);
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        ans = 0;
        total_len = 0;
        G = grid;
        int startx, starty;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(G[i][j] == 1) {
                    startx = i; starty = j;
                } else if(G[i][j] == 2) {
                    endx = i; endy = j;
                } else if(G[i][j] == 0) {
                    total_len++;
                }
            }
        }
        map<pair<int, int>, int> seen;
        seen[make_pair(startx, starty)] = 1;
        // dfs(startx, starty, 0, seen);
        dfs(startx, starty + 1, 1, seen);
        dfs(startx, starty - 1, 1, seen);
        dfs(startx + 1, starty, 1, seen);
        dfs(startx - 1, starty, 1, seen);
        return ans;
    }
};