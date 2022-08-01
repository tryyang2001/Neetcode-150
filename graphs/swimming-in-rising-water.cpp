#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        //use dijkstra to find shortest path        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> frontier;
        int total_time = 0;
        frontier.push({grid[0][0], 0, 0});
        int count = 0;
        while (!frontier.empty() && !visited[grid.size()-1][grid[0].size()-1]) {
            auto& curr = frontier.top();
            int time = curr[0];
            int curr_x = curr[1];
            int curr_y = curr[2];
            frontier.pop();
            visited[curr_x][curr_y] = 1;
            if (time > total_time) {
                total_time = time;
            }
            for (auto& dir : directions) {
                int next_x = dir[0] + curr_x;
                int next_y = dir[1] + curr_y;
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || visited[next_x][next_y]) {
                    continue;
                }
                frontier.push({grid[next_x][next_y], next_x, next_y});
            }
        }
        return total_time;
    }
};