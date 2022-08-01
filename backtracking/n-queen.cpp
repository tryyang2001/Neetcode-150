#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    bool isValid(int row, int col, vector<string>& board) {
        //check each row
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        //check positive diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    void dfs(int curr_row, vector<string>& board, vector<vector<string>>& ans) {
        if (curr_row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isValid(curr_row, col, board)) {
                board[curr_row][col] = 'Q';
                dfs(curr_row + 1, board, ans);
                board[curr_row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        dfs(0, board, ans);
        return ans;
    }
};