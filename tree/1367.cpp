/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int check_list(ListNode* head, TreeNode* root) {
        int result = 1;
        if(head->val == root->val) {
            int l = 0, r = 0;
            if(head->next) {
                if(root->left) {
                    l = check_list(head->next, root->left);
                }
                if(root->right) {
                    r = check_list(head->next, root->right);
                }
                result &= (l | r);
            }
        } else {
            result = 0;
        }
        return result;
    }
    void dfs(ListNode* head, TreeNode* root) {
        ans |= check_list(head, root);
        if(root->left) {
            dfs(head, root->left);
        }
        if(root->right) {
            dfs(head, root->right);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ans = 0;
        dfs(head, root);
        return ans;
    }
};