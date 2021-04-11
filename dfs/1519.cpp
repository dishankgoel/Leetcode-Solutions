class Solution {
public:
    string codes;
    vector<vector<int>> G;
    vector<int> ans;
    vector<int> vis;
    vector<int> dfs(int i) {
        vector<int> curr_count(26); 
        curr_count[codes[i] - 97]++;
        for(int j = 0; j < G[i].size(); j++) {
            int child = G[i][j];
            if(vis[child] == 0) {
                vis[child] = 1;
                vector<int> val = dfs(child);
                for(int k = 0; k < 26; k++) {
                    curr_count[k] += val[k];
                }
            }
        }
        ans[i] = curr_count[codes[i] - 97];
        return curr_count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        codes = labels;
        G = vector<vector<int>>(n);
        ans = vector<int>(n);
        vis = vector<int>(n);
        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vis[0] = 1;
        dfs(0);
        return ans;
    }
};