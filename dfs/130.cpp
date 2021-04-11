#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n, m;
    vector<vector<char>> grid;
    vector<vector<int>> vis;
    int valid(int i, int j) {
        if(i >= 0 && i < n && j >= 0 && j < m) {
            return 1;
        }
        return 0;
    }
    void dfs(int i, int j) {
        if(!valid(i, j)) {
            return;
        }
        if(grid[i][j] == 'X' || vis[i][j] == 1) {
            return;
        }
        vis[i][j] = 1;
        dfs(i, j + 1);
        dfs(i, j - 1);
        dfs(i + 1, j);
        dfs(i - 1, j);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n == 0) {return;}
        m = board[0].size();
        grid = board;
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            dfs(0, j);
            dfs(n - 1, j);
        }
        for(int i = 0; i < n; i++) {
            dfs(i, 0);
            dfs(i, m - 1);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] != 1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};