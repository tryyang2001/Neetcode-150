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
    bool inorder(TreeNode* curr, TreeNode*& prev) {
        if (!curr) {
            return true;
        }
        if (!inorder(curr->left, prev)) {
            return false;
        }
        if (prev && curr->val <= prev->val) {
            return false;
        }
        prev = curr;
        if (!inorder(curr->right, prev)) {
            return false;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
};