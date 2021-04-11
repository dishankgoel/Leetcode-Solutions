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
    int dfs(TreeNode* node) {
        int curr_len = 1;
        int l = 1;
        int r = 1;
        if(node->left) {
            l = dfs(node->left);
            if(node->left->val == node->val) {
                l++;
            } else {
                l = 1;
            }
        }
        if(node->right) {
            r = dfs(node->right);
            if(node->right->val == node->val) {
                r++;
            } else {
                r = 1;
            }
        }
        if(node->left && node->right) {
            if(node->left->val == node->val && node->right->val == node->val) {
                ans = max(ans, l + r - 1);
            }
        }
        ans = max(ans, max(l, r));
        return max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = 1;
        if(!root) {
            return 0;
        }
        dfs(root);
        return ans - 1;
    }
};