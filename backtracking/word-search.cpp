#include <vector>
#include <string>
using namespace std;

class Solution {
public:  

    bool dfs(vector<vector<char>>& board, string& word, int word_idx, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[word_idx]) {
            return false; //out of bound
        }
        if (word_idx == word.size() - 1) {
            return true;
        }
        board[i][j] = '#'; //to indicate visited
        if (dfs(board, word, word_idx + 1, i - 1, j) || dfs(board, word, word_idx + 1, i + 1, j) || dfs(board, word, word_idx + 1, i, j - 1) || dfs(board, word, word_idx + 1, i, j + 1)) {
            return true;
        }
        board[i][j] = word[word_idx];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (board[row][col] == word[0] && dfs(board, word, 0, row, col)) {
                    return true;
                }
            }
        }
        return false;
    }
};