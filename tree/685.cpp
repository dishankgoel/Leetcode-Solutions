class Solution {
public:
    vector<int> vis;
    void dfs(vector<int> G[], int node) {
        for(int i = 0; i < G[node].size(); i++) {
            int child = G[node][i];
            if(vis[child] != 1) {
                vis[child] = 1;
                dfs(G, child);
            }
        }
    } 
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> G[n];
        vector<int> invG[n];
        map<pair<int, int>, int> order;
        vector<int> indegree(n);
        for(int i = 0; i < n; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            G[u].push_back(v);
            invG[v].push_back(u);
            order[{u,v}] = i;
            indegree[v]++;
        }
        vector<int> ans(2);
        int fault_node = -1;
        int root_node = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 2) {
                fault_node = i;
            }
            if(indegree[i] == 0) {
                root_node = i;
            }
        }
        if(fault_node != -1 && root_node == -1) {
            int op1 = invG[fault_node][0], op2 = invG[fault_node][1]; 
            if(order[make_pair(op1, fault_node)] < order[make_pair(op2, fault_node)]) {
                ans[0] = op2 + 1; ans[1] = fault_node + 1;   
            } else {
                ans[0] = op1 + 1; ans[1] = fault_node + 1;   
            }
        } else if(fault_node != -1) {
            vector<int> newG[n];
            int op1 = invG[fault_node][0], op2 = invG[fault_node][1];
            for(int i = 0; i < n; i++) {
                newG[i] = G[i];
            }
            vector<int> newop;
            for(int i = 0; i < newG[op1].size(); i++) {
                if(newG[op1][i] != fault_node) {
                    newop.push_back(newG[op1][i]);
                }
            }
            newG[op1] = newop;
            vis = vector<int>(n);
            vis[root_node] = 1;
            dfs(newG, root_node);
            int a1 = 0, a2 = 0;
            if(vis[fault_node] != 1) {
                ans[0] = op2 + 1; ans[1] = fault_node + 1;   
            } else {
                for(int i = 0; i < n; i++) {
                    newG[i] = G[i];
                }
                newop.clear();
                for(int i = 0; i < newG[op2].size(); i++) {
                    if(newG[op2][i] != fault_node) {
                        newop.push_back(newG[op2][i]);
                    }
                }
                newG[op2] = newop;
                vis = vector<int>(n);
                vis[root_node] = 1;
                dfs(newG, root_node);
                if(vis[fault_node] == 1) {
                    if(order[make_pair(op1, fault_node)] < order[make_pair(op2, fault_node)]) {
                        ans[0] = op2 + 1; ans[1] = fault_node + 1;   
                    } else {
                        ans[0] = op1 + 1; ans[1] = fault_node + 1;   
                    }
                } else {
                    ans[0] = op1 + 1; ans[1] = fault_node + 1;   
                }
                
            }
        } else {
            vector<int> answers;
            for(int i = 0; i < n; i++) {
                vis = vector<int>(n);
                vis[i] = 1;
                dfs(G, i);
                int all_visited = 1;
                for(int j = 0; j < n; j++) {
                    if(vis[j] != 1) {
                        all_visited = 0;break;
                    }
                }
                if(all_visited) {
                    answers.push_back(i);
                }
            }
            pair<int, int> curr = {invG[answers[0]][0], answers[0]};
            for(int i = 1; i < answers.size(); i++) {
                if(order[curr] < order[make_pair(invG[answers[i]][0], answers[i])]) {
                    curr = make_pair(invG[answers[i]][0], answers[i]);
                }
            }
            ans[0] = curr.first + 1; ans[1] = curr.second + 1;
        }
        return ans;
    }
};