#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }
        //replace zero's corresponding row and col to 0
        for (auto& pos : zeros) {
            //row
            for (int i = 0; i < matrix[pos[0]].size(); i++) {
                matrix[pos[0]][i] = 0;
            }
            //col
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][pos[1]] = 0;
            }
        }
    }
};