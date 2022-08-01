#include <string>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void preorder(TreeNode* curr, string& data) {
        if (!curr) {
            data += "N ";
            return;
        }
        data += to_string(curr->val) + " ";
        preorder(curr->left, data);
        preorder(curr->right, data);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string data = "";
        preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        istringstream in(data);
        TreeNode* root = construct(in);
        return root;
    }
    
    TreeNode* construct(istringstream& in) {
        string value = "";
        in >> value;
        if (value == "N") {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(value));
        root->left = construct(in);
        root->right = construct(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));