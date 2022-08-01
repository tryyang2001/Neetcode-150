#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(), 0);
        vector<int> frontier(points.size(), INT_MAX);
        frontier[0] = 0;
        int count = 0;
        int total_cost = 0;
        while (count < points.size()) {
            int curr_min = INT_MAX;
            int curr_point = -1;
            for (int i = 0; i < points.size(); i++) {
                if (!visited[i] && frontier[i] < curr_min) {
                    curr_min = frontier[i];
                    curr_point = i;
                }
            }
            total_cost += curr_min;
            count++;
            visited[curr_point] = 1;
            for (int i = 0; i < points.size(); i++) {
                if (visited[i]) {
                    continue;
                }
                int dist = abs(points[i][0] - points[curr_point][0]) + 
                    abs(points[i][1] - points[curr_point][1]);
                if (dist < frontier[i]) {
                    frontier[i] = dist;
                }
            }
        }
        return total_cost;
    }
};