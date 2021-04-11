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
class Solution {
public:
    int ans;
    vector<pair<int, int>> widths;
    void dfs(TreeNode* root, int x, int y) {
        widths[y].first = min(widths[y].first, x);
        widths[y].second = max(widths[y].second, x);
        // 2**y 
        // ans = max(ans, widths[y].second - widths[y].first);
        if(root->left) {
            dfs(root->left, x - 1, y + 1);
        }
        if(root->right) {
            dfs(root->right, x + 1, y + 1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        widths = vector<pair<int, int>>(3001, make_pair(4000, -4000));
        dfs(root, 0, 0);
        return ans;
    }
};