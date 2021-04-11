/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Coordinates {
public:
    TreeNode* node;
    int x;
    int y;
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<vector<int>>> m;
        queue<Coordinates> Q;
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        Coordinates base_node;
        base_node.node = root;
        base_node.x = 0;
        base_node.y = 1000;
        vector<vector<int>> with_y(1001);
        with_y[1000] = {root->val};
        m[0] = with_y;
        Q.push(base_node);
        while(!Q.empty()) {
            Coordinates curr = Q.front();
            Coordinates right,left;
            right.node = curr.node->right;
            right.x = curr.x + 1; right.y = curr.y - 1;
            left.node = curr.node->left;
            left.x = curr.x - 1; left.y = curr.y - 1;
            if(left.node != NULL) {
                if(m.find(left.x) == m.end()) {
                    vector<vector<int>> with_y(1001);
                    with_y[left.y].push_back(left.node->val);
                    m[left.x] = with_y;
                } else {
                    m[left.x][left.y].push_back(left.node->val);
                }
                Q.push(left);
            }
            if(right.node != NULL) {
                if(m.find(right.x) == m.end()) {
                    vector<vector<int>> with_y(1001);
                    with_y[right.y].push_back(right.node->val);
                    m[right.x] = with_y;
                } else {
                    m[right.x][right.y].push_back(right.node->val);
                }
                Q.push(right);
            }
            Q.pop();
        }
        for(int i = -1000; i < 1000; i++) {
            if(m.find(i) != m.end()) {
                vector<vector<int>> curr = m[i];
                vector<int> nodes;
                for(int j = curr.size() - 1; j >= 0; j--) {
                    if(!curr[j].empty()) {
                        sort(curr[j].begin(), curr[j].end());
                        nodes.insert(nodes.end(), curr[j].begin(), curr[j].end());
                    }
                }
                ans.push_back(nodes);
            }
        }
        return ans;
    }
};