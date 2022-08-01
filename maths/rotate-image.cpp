#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left < right) {
            for (int i = 0; i < right - left; i++) {
                int top = left;
                int bottom = right;
                //save top left element
                int topleft = matrix[top][left + i];
                //shift bottom left to top left
                matrix[top][left + i] = matrix[bottom - i][left];
                //shift bottom right to bottom left
                matrix[bottom - i][left] = matrix[bottom][right - i];
                //shift top right to bottom right
                matrix[bottom][right - i] = matrix[top + i][right];
                //shift top left to top right
                matrix[top + i][right] = topleft;
            }
            left++;
            right--;
        }
    }
};