#include <utility>
using namespace std;
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
    int dfs(TreeNode* curr, int& max_path) {
        if (!curr) {
            return 0;
        }
        int left_max = dfs(curr->left, max_path);
        int right_max = dfs(curr->right, max_path);
        left_max = (left_max < 0)? 0 : left_max;
        right_max = (right_max < 0)? 0 : right_max;
        max_path = max(max_path, curr->val + left_max + right_max); //when splitting
        return curr->val + max(left_max, right_max); //without splitting, must choose one path
    }
    
    int maxPathSum(TreeNode* root) {
        int max_path = root->val;
        dfs(root, max_path);
        return max_path;
    }
};