class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = m;
        vector<int> group(n, -1);
        vector<int> ans;
        int curr_group = 1;
        for(int i = 0; i < m; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            if(group[u] == -1 && group[v] == -1) {
                group[u] = curr_group;
                group[v] = curr_group;
                curr_group++;
            } else if(group[v] == -1) {
                group[v] = group[u];
            } else if(group[u] == -1) {
                group[u] = group[v];
            } else if(group[u] == group[v]) {
                ans.push_back(u + 1);
                ans.push_back(v + 1);
                break;
            } else {
                int new_group = group[u];
                int old_group = group[v];
                for(int j = 0; j < n; j++) {
                    // NOTE: Doing group[j] == group[v] did not work for some reason?? 
                    if(group[j] == old_group) {
                        group[j] = new_group;
                    }
                }
            }
        }
        return ans;
    }
};