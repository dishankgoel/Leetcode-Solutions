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
    void delete_node(TreeNode* root, TreeNode* parent, int dir) {
        if(root->right == NULL) {
            if(dir) {
                parent->right = root->left;
            } else {
                parent->left = root->left;
            }
        } else if(root->right->left == NULL) {
            if(dir) {
                parent->right = root->right;
            } else {
                parent->left = root->right;
            }
            root->right->left = root->left;
        } else {
            TreeNode* curr = root->right;
            TreeNode* next = root->right->left;
            while(next->left != NULL) {
                curr = next;
                next = next->left;
            }
            curr->left = next->right;
            root->val = next->val;
        }
    }
    void bst_search(TreeNode* root, int key, TreeNode* parent, int dir) {
        if(root == NULL) {
            return;
        }
        if(root->val == key) {
            delete_node(root, parent, dir);
        } else {
            if(root->val > key) {
                bst_search(root->left, key, root, 0);
            } else {
                bst_search(root->right, key, root, 1);
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {return root;}
        if(root->val == key) {
            if(root->right == NULL) {
                root = root->left;
                return root;    
            } else if (root->right->left == NULL) {
                root->right->left = root->left;
                root = root->right;
                return root;
            }
        }
        bst_search(root, key, root, 0);
        return root;
    }
};