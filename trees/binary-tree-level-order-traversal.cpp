#include <vector>
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
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return ans;
        }
        queue<TreeNode*> frontier;
        frontier.push(root);
        while (!frontier.empty()) {
            int count = frontier.size();
            vector<int> same_level;
            for (int i = 0; i < count; i++) {
                TreeNode* curr = frontier.front();
                frontier.pop();
                same_level.push_back(curr->val);
                if (curr->left) {
                    frontier.push(curr->left);
                }
                if (curr->right) {
                    frontier.push(curr->right);
                }
            }
            ans.push_back(same_level);
        }
        return ans;
    }
};