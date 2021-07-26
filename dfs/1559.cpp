class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<char>> G;
    int n, m; 
    int valid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        return 1;
    }
    int dfs(int i, int j, int dir) {
        int ans = 0;
        if(vis[i][j] == 1) {
            return 1;
        }
        vis[i][j] = 1;
        if(dir&(1<<0)) {
            if(valid(i - 1, j)) {
                if(G[i][j] == G[i - 1][j]) {
                    ans |= dfs(i - 1, j, (1<<0|1<<1|1<<3));
                }
            } 
        }
        if(dir&(1<<1)) {
            if(valid(i, j + 1)) {
                if(G[i][j] == G[i][j + 1]) {
                    ans |= dfs(i, j + 1, (1<<0|1<<1|1<<2));
                }
            } 
        }
        if(dir&(1<<2)) {
            if(valid(i + 1, j)) {
                if(G[i][j] == G[i + 1][j]) {
                    ans |= dfs(i + 1, j, (1<<1|1<<2|1<<3));
                }
            } 
        }
        if(dir&(1<<3)) {
            if(valid(i, j - 1)) {
                if(G[i][j] == G[i][j - 1]) {
                    ans |= dfs(i, j - 1, (1<<0|1<<2|1<<3));
                }
            } 
        }
        return ans;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        G = grid;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0) {
                    ans |= dfs(i, j, (1<<0|1<<1|1<<2|1<<3));
                }
            }
        }
        return ans;
    }
};