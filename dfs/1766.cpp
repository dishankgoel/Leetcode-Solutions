#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> coprimes;
    vector<int> ans;
    vector<int> val;
    vector<int> vis;
    vector<vector<int>> G;

    void dfs(int node, int last_seen[]) {

        ans[node] = last_seen[val[node]];

        int new_last_seen[51];
        for(int i = 0; i < 51; i++) {new_last_seen[i] = last_seen[i];}
        
        for(int i = 0; i < coprimes[val[node]].size(); i++) {
            int v = coprimes[val[node]][i];
            new_last_seen[v] = node;
        }
        
        for(int i = 0; i < G[node].size(); i++) {
            int c = G[node][i];
            if(vis[c] == 0) {
                vis[c] = 1;
                dfs(c, new_last_seen);
            }
        }
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        coprimes = vector<vector<int>>(51);
        ans = vector<int>(nums.size());
        val = nums;
        vis = vector<int>(nums.size(), 0);
        G = vector<vector<int>>(nums.size());
        
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for(int a = 1; a <= 50; a++) {
            for(int b = 1; b <= 50; b++) {
                if(__gcd(a, b) == 1) {
                    coprimes[a].push_back(b);
                }
            }
        }

        ans[0] = -1;

        int last_seen[51];
        for(int i = 0; i < 51; i++) {last_seen[i] = -1;}
        
        vis[0] = 1;
        dfs(0, last_seen);
        return ans;
    }
};