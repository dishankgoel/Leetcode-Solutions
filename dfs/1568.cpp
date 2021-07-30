class Solution {
public:
    
    vector<vector<int>> G;
    vector<vector<int>> vis;
    int n, m;
    int valid(int i , int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        return 1;
    }
    void dfs(int i, int j) {
        if(!valid(i, j) || vis[i][j] == 1 || G[i][j] == 0) {
            return;
        }
        vis[i][j] = 1;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
    int numIslands() {
        int ans = 0;
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && G[i][j] == 1) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;

    }
    int minDays(vector<vector<int>>& grid) {
        G = grid;
        n = grid.size(), m = grid[0].size();
        int ans = numIslands();
        if(ans > 1) {
            return 0;
        }
        int ans_is_1 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(G[i][j] == 1) {
                    G[i][j] = 0;
                    int curr = numIslands();
                    if(curr > 1 || curr == 0) {
                        ans_is_1 = 1;
                    }
                    G[i][j] = 1;
                }
            }
        }
        if(ans_is_1) {
            return 1;
        }
        return 2;
    }
};