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
    int max_depth = 0;
    void dfs(TreeNode* curr, int curr_depth) {
        if (!curr) {
            if (curr_depth > max_depth) {
                max_depth = curr_depth;
            }
            return;
        }
        dfs(curr->left, curr_depth + 1);
        dfs(curr->right, curr_depth + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return max_depth;
    }
};