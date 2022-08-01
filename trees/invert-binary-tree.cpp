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
    void dfs(TreeNode* curr) {
        if (!curr) {
            return;
        }     
        if (curr->left) {
            dfs(curr->left);
        }
        if (curr->right) {
            dfs(curr->right);
        }
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        return;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};