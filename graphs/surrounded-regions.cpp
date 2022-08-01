#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
    struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
        }
    };
    
    unordered_set<pair<int, int>, pair_hash> visited;
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size()) {
            return;
        }
        if (board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'E';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
    
    void solve(vector<vector<char>>& board) {
        //check the border if it contains any 'O'
        for (int i = 0; i < board.size(); i++) {
            dfs(board, i, 0);
            dfs(board, i, board[i].size() - 1);
        }
        for (int i = 0; i < board[0].size(); i++) {
            dfs(board, 0, i);
            dfs(board, board.size() - 1, i);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};