class Solution {
public:
    vector<vector<int>> G;
    vector<int> init;
    int n;
    int bfs(int exclude) {
        int ans = 0;
        queue<int> Q;
        vector<int> vis(n, 0);
        for(int i = 0; i < init.size(); i++) {
            if(init[i] != exclude) {
                vis[init[i]] = 1;
                ans++;
                Q.push(init[i]);
            }
        }
        while(!Q.empty()) {
            int curr = Q.front();
            for(int i = 0; i < G[curr].size(); i++) {
                int child = G[curr][i];
                if(vis[child] == 0) {
                    vis[child] = 1;
                    ans++;
                    Q.push(child);
                }
            }
            Q.pop();
        }
        return ans;
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n = graph.size(); init = initial;
        G = vector<vector<int>>(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] == 1) { 
                    G[i].push_back(j);
                }
            }
        }
        int min_num = n + 1;
        int ans = initial[0];
        for(int i = 0; i < initial.size(); i++) {
            int new_num = bfs(initial[i]);
            if(new_num < min_num) {
                min_num = new_num;
                ans = initial[i];
            } else if(new_num == min_num) {
                ans = min(ans, initial[i]);
            }
        }
        return ans;
        
    }
};