#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        while (left <= right && top <= bottom) {
            //top row left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            //last col top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                //last row right to left
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if (left <= right) {
                //first col bottom to top
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};