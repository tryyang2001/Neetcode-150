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
    vector<int> in;
    void inorder(TreeNode* curr, int k) {
        if (!curr) {
            return;
        }
        inorder(curr->left, k);
        if (in.size() == k) {
            return;
        }
        in.push_back(curr->val);
        inorder(curr->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return in[in.size()-1];
    }
};