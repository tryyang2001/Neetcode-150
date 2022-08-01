#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int longest = 0;
    vector<vector<int>> dr = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& dp) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() || matrix[i][j] <= prev) {
            return 0;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        //scan for surrounding
        for (auto& dir : dr) {
            int x = dir[0] + i;
            int y = dir[1] + j;
            int cum = dfs(matrix, x, y, matrix[i][j], dp) + 1;
            dp[i][j] = max(dp[i][j], cum);
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                longest = max(longest, dfs(matrix, i, j, -1, dp));
            }
        }
        /*for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        return longest;
    }
};