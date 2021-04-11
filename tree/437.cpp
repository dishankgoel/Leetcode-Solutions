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
    int su;
    void dfs(TreeNode* root, unordered_map<int, int> a, int curr) {
        curr += root->val;
        ans += a[curr - su];
        a[curr]++;
        if(root->left) {
            unordered_map<int, int> l = a;
            dfs(root->left, l, curr);
        }
        if(root->right) {
            unordered_map<int, int> r = a;
            dfs(root->right, r, curr);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        su = sum;
        unordered_map<int, int> a;
        a[0] = 1;
        if(root == NULL) {return 0;}
        dfs(root, a, 0);
        return ans;
    }
};