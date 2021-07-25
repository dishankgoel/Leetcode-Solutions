class Solution {
public:
    vector<vector<int>> G;
    vector<int> vis;
    int n;
    int findsimilar(string s1, string s2) {
        int m = s1.size();
        int diff = 0;
        for(int i = 0; i < m; i++) {
            if(s1[i] != s2[i]) {diff++;}
        }
        return diff == 2 || diff == 0;
    }
    void dfs(int node) {
        for(int i = 0; i < G[node].size(); i++) {
            int child = G[node][i];
            if(vis[child] == 0) {
                vis[child] = 1;
                dfs(child);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        G = vector<vector<int>>(n);
        vis = vector<int>(n, 0); 
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(findsimilar(strs[i], strs[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }  
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                ans++;
                vis[i] = 1;
                dfs(i);
            }
        }
        return ans;   
    }
};