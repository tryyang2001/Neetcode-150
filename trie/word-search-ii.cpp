#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int str_idx = -1;
    
    TrieNode () {

    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<string> ans;
    
    void dfs(vector<vector<char>>& board, vector<string>& words, int i, int j, TrieNode* curr) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '-') {
            return;
        }
        if (curr->children.find(board[i][j]) == curr->children.end()) {
            return;
        }
        //explore all directions
        TrieNode* next = curr->children[board[i][j]];
        char c = board[i][j];
        board[i][j] = '-';
        if (next->str_idx != -1) {
            ans.push_back(words[next->str_idx]);
            next->str_idx = -1;
        }
        dfs(board, words, i - 1, j, next);
        dfs(board, words, i + 1, j, next);
        dfs(board, words, i, j - 1, next);
        dfs(board, words, i, j + 1, next);
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //create trie by using the words array
        TrieNode* curr;
        for (int i = 0; i < words.size(); i++) {
            curr = root;
            for (auto& c : words[i]) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->str_idx = i;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(board, words, i, j, root);
            }
        }
        return ans;
    }
};