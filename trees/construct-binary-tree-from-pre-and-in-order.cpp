#include <vector>
#include <algorithm>
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
    /*void print(vector<int> v) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }*/

    TreeNode* construct(vector<int>& pre, vector<int>& in) {
        if (!pre.size() || !in.size()) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);
        int mid = find(in.begin(), in.end(), pre[0]) - in.begin();
        vector<int> left_pre (pre.begin() + 1, pre.begin() + mid + 1);
        vector<int> right_pre (pre.begin() + mid + 1, pre.end());
        vector<int> left_in (in.begin(), in.begin() + mid);
        vector<int> right_in (in.begin() + mid + 1, in.end());
        root->left = construct(left_pre, left_in);
        root->right = construct(right_pre, right_in);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = construct(preorder, inorder);
        return root;
    }
};