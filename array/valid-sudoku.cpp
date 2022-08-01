#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row_checker;
        unordered_set<char> col_checker;
        for (int i = 0; i < board.size(); i++) {
            row_checker.clear();
            col_checker.clear();
            for (int j = 0; j < board[i].size(); j++) {
                //check if is row valid
                if (board[i][j] != '.') {
                    if (row_checker.find(board[i][j]) != row_checker.end()) {
                        return false;
                    }
                    row_checker.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (col_checker.find(board[j][i]) != col_checker.end()) {
                        return false;
                    }
                    col_checker.insert(board[j][i]);
                }
                
            }
            /*
            //printing
            cout << "Checking row:" << endl;
            for (auto& n : row_checker) {
                cout << n << " ";
            }
            cout << endl;
            cout << "Checking col:" << endl;
            for (auto& n : col_checker) {
                cout << n << " ";
            }
            cout << endl;*/
        }
        //check if is square valid
        unordered_set<char> square1_checker;
        unordered_set<char> square2_checker;
        unordered_set<char> square3_checker;
        for (int i = 0; i < board.size(); i++) {
            if (i % 3 == 0) {
                /*
                cout << "Square 1:" << endl;
                for (auto& n : square1_checker) {
                    cout << n << " " << endl;
                }
                cout << "Square 2:" << endl;
                for (auto& n : square2_checker) {
                    cout << n << " " << endl;
                }
                cout << "Square 3:" << endl;
                for (auto& n : square3_checker) {
                    cout << n << " " << endl;
                }*/
                square1_checker.clear();
                square2_checker.clear();
                square3_checker.clear();
            }
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != '.') {
                    if (square1_checker.find(board[i][j]) != square1_checker.end()) {
                        return false;
                    }
                    square1_checker.insert(board[i][j]);
                }
            }
            for (int j = 3; j < 6; j++) {
               if (board[i][j] != '.') {
                    if (square2_checker.find(board[i][j]) != square2_checker.end()) {
                        return false;
                    }
                    square2_checker.insert(board[i][j]);
                }
            }
            for (int j = 6; j < 9; j++) {
               if (board[i][j] != '.') {
                    if (square3_checker.find(board[i][j]) != square3_checker.end()) {
                        return false;
                    }
                    square3_checker.insert(board[i][j]);
                }
            }
        }
        return true;
    }
};