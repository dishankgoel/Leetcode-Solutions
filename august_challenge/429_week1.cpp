#include <bits/stdc++.h>

using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        queue<pair<Node*, int>> Q;
        int curr = 0;
        vector<int> same_level;
        Q.push({root, curr});
        while(!Q.empty()) {
            Node* c = Q.front().first; int d = Q.front().second;
            if(curr != d) {
                curr++;
                ans.push_back(same_level);
                same_level.clear();
            }
            same_level.push_back(c->val);
            for(int i = 0; i < c->children.size(); i++) {
                Q.push({c->children[i], d + 1});
            }
            Q.pop();
        }
        ans.push_back(same_level);
        return ans;
        
    }
};