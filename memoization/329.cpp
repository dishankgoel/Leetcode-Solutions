#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> visited;
    int check_valid(int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if(i >= 0 && i < n && j >= 0 && j < m) {
            return 1;
        } else {
            return 0;
        }
    }
    int dfs(int i, int j) {
        int ans = 1;
        if(visited[i][j] != 0) {
            return visited[i][j];
        }
        if( check_valid(i, j + 1) && grid[i][j + 1] > grid[i][j]) {
            ans = max(ans, dfs(i, j + 1) + 1);
        }
        if( check_valid(i, j - 1) && grid[i][j - 1] > grid[i][j]) {
            ans = max(ans, dfs(i, j - 1) + 1);
        }
        if( check_valid(i + 1, j) && grid[i + 1][j] > grid[i][j]) {
            ans = max(ans, dfs(i + 1, j) + 1);
        }
        if( check_valid(i - 1, j) && grid[i - 1][j] > grid[i][j]) {
            ans = max(ans, dfs(i - 1, j) + 1);
        }
        visited[i][j] = ans;  
        return ans;  
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        grid = matrix;
        visited.resize(n, vector<int>(m, 0));
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0) {
                    ans = max(ans, dfs(i, j));
                } else {
                    ans = max(ans, visited[i][j]);
                }
            }
        }
        return ans;
    }
};