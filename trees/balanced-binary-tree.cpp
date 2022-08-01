#include <math.h>
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
    bool dfs(TreeNode* curr, int& height) {
        if (!curr) {
            height = -1;
            return true;
        }
        int left, right;
        if (!dfs(curr->left, left) || !dfs(curr->right, right)) {
            return false;
        }
        if (abs(left - right) > 1) {
            return false;
        }
        height = 1 + max(left, right);
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }
};