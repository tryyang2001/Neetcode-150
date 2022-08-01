#include <vector>
using namespace std;

class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size()) {
            return 0;
        }
        if (grid[x][y] == 0) {
            return 0;
        }
        if (visited[x][y]) {
            return 0;
        }
        visited[x][y] = 1;
        int area = 1 + dfs(grid, x - 1, y, visited) + dfs(grid, x + 1, y, visited) + dfs(grid, x, y - 1, visited) + dfs(grid, x, y + 1, visited);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(grid, i, j, visited);
                    max_area = (area > max_area)? area : max_area;
                }
            }
        }
        return max_area;
    }
};