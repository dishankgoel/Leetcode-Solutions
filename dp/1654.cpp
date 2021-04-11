#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        unordered_map<int, int> not_allowed;
        unordered_map<int, int> ans, vis, back_nodes;
        int max_notallowed = 0;
        for(auto i : forbidden) {
            not_allowed[i] = 1;
            max_notallowed = max(max_notallowed, i);
        }
        queue<int> Q;
        ans[x] = -1;
        ans[0] = 0;
        Q.push(0);
        while(!Q.empty() && (ans[x] == -1)) {
            int curr = Q.front();
            vis[curr] = 1;
            if(not_allowed.find(curr) == not_allowed.end()) {
                int back = curr - b;
                int front = curr + a;
                if(back >= 0 && not_allowed.find(back) == not_allowed.end() && vis[back] == 0) {
                    ans[back] = ans[curr] + 1;
                    vis[back] = 1;
                    int new_front = back + a;
                    if(not_allowed.find(new_front) == not_allowed.end() && vis[new_front] == 0) {
                        ans[new_front] = ans[back] + 1;
                        if(new_front <= a + b + max(x, max_notallowed)) {
                            Q.push(new_front);
                        }
                    } 
                }
                if(not_allowed.find(front) == not_allowed.end() && vis[front] == 0) {
                    ans[front] = ans[curr] + 1;
                    if(front <= a + b + max(x, max_notallowed)) {
                        Q.push(front);
                    }
                }
            }
            Q.pop();
        }
        return ans[x];
    }
};