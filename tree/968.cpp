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
    // States
    // 0 -> No camera and not covered
    // 1 -> No camera and covered
    // 2 -> Camera placed
    vector<vector<int>> dp;

    int dfs(TreeNode* root, int state) {
        int ans = 1e5;
        if(root == NULL) {
            return 0;
        }
        if(dp[root->val][state] != -1) {
            return dp[root->val][state];
        }
        int l0 = dfs(root->left, 0), r0 = dfs(root->right, 0);
        int l1 = dfs(root->left, 1), r1 = dfs(root->right, 1);
        int l2 = 1e5, r2 = 1e5;
        if(root->left) {l2 = min(l2, dfs(root->left, 2));}
        if(root->right) {r2 = min(r2, dfs(root->right, 2));} 
        if(state == 0) {
            ans = min(ans, l1 + r1 + 1);
            ans = min(ans, l2 + r0);
            ans = min(ans, l0 + r2);
            ans = min(ans, l2 + r2);
        } else if(state == 1) {
            ans = min(ans, l1 + r1 + 1);
            ans = min(ans, l0 + r0);
            ans = min(ans, l2 + r0);
            ans = min(ans, l0 + r2);
            ans = min(ans, l2 + r2);
        } else if(state == 2) {
            ans = min(ans, l1 + r1 + 1);
            ans = min(ans, l2 + r0 + 1);
            ans = min(ans, l0 + r2 + 1);
            ans = min(ans, l2 + r2 + 1);
        }
        dp[root->val][state] = ans;
        return ans;
    }
    int minCameraCover(TreeNode* root) {
        dp = vector<vector<int>>(1000, vector<int>(3, -1));
        queue<TreeNode*> Q;
        int curr = 0;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode* p = Q.front();
            if(p->left) {
                Q.push(p->left);
            }
            if(p->right) {
                Q.push(p->right);
            }
            p->val = curr;
            curr++;
            Q.pop();
        } 
        return dfs(root, 0);
    }
};