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
    int dfs(TreeNode* curr, int& curr_length) {
        if (!curr) {
            return 0;
        }
        int left = dfs(curr->left, curr_length);
        int right = dfs(curr->right, curr_length);
        curr_length = max(curr_length, left + right);
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        //for every node, find the largest depth of its subtrees
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};