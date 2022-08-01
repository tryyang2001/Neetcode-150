#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_start = 0;
        int row_end = matrix.size() - 1;
        while (row_start <= row_end) {
            int row_mid = (row_start + row_end) / 2;
            if (matrix[row_mid][0] == target) {
                return true;
            } else if (matrix[row_mid][0] < target) {
                if (row_mid < matrix.size() - 1) {
                    if (matrix[row_mid + 1][0] == target) {
                        return true;
                    } else if (matrix[row_mid + 1][0] < target) {
                        row_start = row_mid + 1;
                        continue;
                    }
                }
                //search through current row
                int start = 0;
                int end = matrix[row_mid].size() - 1;
                while (start <= end) {
                    int mid = (start + end) / 2;
                    if (matrix[row_mid][mid] == target) {
                        return true;
                    } else if (matrix[row_mid][mid] < target) {
                       start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                return false;
            } else {
                row_end = row_mid - 1;
            }
        }
        return false;
    }
};