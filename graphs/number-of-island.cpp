#include <vector>
using namespace std;

class Solution {
public:
    //self-defined hash is too slow to compute...
    /*struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
        }
    };
    unordered_set<pair<int, int>, pair_hash> visited;*/
        
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<int>>& visited) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size()) {
            return;
        }
        if (grid[x][y] == '0') {
            return;
        }
        if (visited[x][y] == 1) {
            return;
        }
        //visited.insert(make_pair(x, y));
        visited[x][y] = 1;
        //explore four direction
        dfs(grid, x - 1, y, visited);
        dfs(grid, x + 1, y, visited);
        dfs(grid, x, y - 1, visited);
        dfs(grid, x, y + 1, visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};