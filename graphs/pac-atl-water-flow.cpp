#include< vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int x, int y, int previous_height, vector<vector<bool>>& visited) {
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[x].size()) {
            return;
        }
        if (visited[x][y] || heights[x][y] < previous_height) {
            return;
        }
        visited[x][y] = 1;
        dfs(heights, x - 1, y, heights[x][y], visited);
        dfs(heights, x + 1, y, heights[x][y], visited);
        dfs(heights, x, y - 1, heights[x][y], visited);
        dfs(heights, x, y + 1, heights[x][y], visited);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, heights[i][0], pacific);
            dfs(heights, i, n - 1, heights[i][n-1], atlantic);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, 0, i, heights[0][i], pacific);
            dfs(heights, m - 1, i, heights[m-1][i], atlantic);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};