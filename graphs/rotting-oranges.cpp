#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> frontier;
        //count number of orange, and find the initially rotten one
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    frontier.push(make_pair(i, j));
                }
            }
        }
        if (fresh == 0) {
            return 0; //there is no fresh orange, so no time is needed to spend
        }
        int time = 0;
        while (!frontier.empty() && fresh > 0) {
            int length = frontier.size();
            for (int i = 0; i < length; i++) {
                pair<int, int> curr = frontier.front();
                frontier.pop();
                //cout << "current: " << curr.first << " " << curr.second << endl;
                for (auto& dr : directions) {
                    int x = dr[0] + curr.first;
                    int y = dr[1] + curr.second;
                    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) {
                        continue;
                    }
                    //cout << "next rotten: " << x << " " << y << endl;
                    grid[x][y] = 2;
                    fresh--;
                    frontier.push(make_pair(x, y));
                }
            }
            time++;
        }
        return (fresh == 0)? time : -1;
    }
};