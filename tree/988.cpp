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
    string dfs(TreeNode* root, string curr) {
        if(root == NULL) {
            return "";
        }
        curr.insert(0, 1, (char)root->val + 97);
        string s1 = dfs(root->left, curr);
        string s2 = dfs(root->right, curr);
        if(root->left == NULL) {
            s2.push_back((char)root->val + 97);
            return s2;
        }
        if(root->right == NULL) {
            s1.push_back((char)root->val + 97);
            return s1;
        }
        string c1 = s1 + curr;
        string c2 = s2 + curr;
        s1.push_back((char)root->val + 97); 
        s2.push_back((char)root->val + 97);
        string ans = c1 < c2 ? s1 : s2;
        return ans;
    }
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
};