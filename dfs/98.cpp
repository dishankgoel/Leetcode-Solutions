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
#define ll long long
class Solution {
public:

	bool dfs(TreeNode* node, ll b, ll e) {
		int ans = 1;
		if(node->val >= e || node->val <= b) {
			return 0;
		}
		if(node->right) {
			ans &= dfs(node->right, node->val, e);
		}
		if(node->left) {
			ans &= dfs(node->left, b, node->val);
		}
		return ans;

	}
	bool isValidBST(TreeNode* root)	{
		if(root == NULL) {return true;}
		int ans = dfs(root, (ll)INT_MIN - 10, (ll)INT_MAX + 10);
		return ans;
	}
};
