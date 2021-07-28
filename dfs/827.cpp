class Solution {
public:
    vector<vector<int>> d;
    vector<vector<int>> vis;
    vector<vector<int>> G;
    int n;
    int curr;
    int valid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        } 
        return 1;
    }
    int dfs(int i, int j) {
        if(!valid(i, j) || G[i][j] == 0 || vis[i][j] == 1) {
            return 0;
        }
        vis[i][j] = 1;
        d[i][j] = curr;
        int ans = 1;
        ans += dfs(i + 1, j);
        ans += dfs(i, j + 1);
        ans += dfs(i - 1, j);
        ans += dfs(i, j - 1);
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        G = grid;
        d = vector<vector<int>>(n, vector<int>(n, 0));
        vis = vector<vector<int>>(n, vector<int>(n, 0));
        vector<int> dis(n*n + 2, 0);
        curr = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    int m = dfs(i, j);
                    dis[curr - 1] = m;
                    curr++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < dis.size(); i++) {
            ans = max(ans, dis[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int this_flip = 1;
                    unordered_map<int, int> p;
                    if(valid(i + 1, j)) {
                        int a = d[i + 1][j];
                        if(p.find(a) == p.end() && a != 0) {
                            this_flip += dis[a - 1];
                            p[a] = 1;
                        }
                    }
                    if(valid(i - 1, j)) {
                        int a = d[i - 1][j];
                        if(p.find(a) == p.end() && a != 0) {
                            this_flip += dis[a - 1];
                            p[a] = 1;
                        }
                    }
                    if(valid(i, j - 1)) {
                        int a = d[i][j - 1];
                        if(p.find(a) == p.end() && a != 0) {
                            this_flip += dis[a - 1];
                            p[a] = 1;
                        }
                    }
                    if(valid(i, j + 1)) {
                        int a = d[i][j + 1];
                        if(p.find(a) == p.end() && a != 0) {
                            this_flip += dis[a - 1];
                            p[a] = 1;
                        }
                    }
                    ans = max(ans, this_flip);
                }
            }
        }
        return ans;
    }
};