#include <vector>
#include <stack>
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
    vector<int> view;
    int max_level = 0;
    
    void dfs(stack<pair<TreeNode*, int>> frontier) {
        if (frontier.empty()) {
            return;
        }
        TreeNode* curr = frontier.top().first;
        int level = frontier.top().second;
        frontier.pop();
        if (level == max_level) {
            view.push_back(curr->val);
            max_level++;
        }
        if (curr->left) {
            frontier.push({curr->left, level + 1});
        }
        if (curr->right) {
            frontier.push({curr->right, level + 1});
        }
        dfs(frontier);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        stack<pair<TreeNode*, int>> frontier;
        frontier.push({root, 0});
        dfs(frontier);
        return view;
    }
};