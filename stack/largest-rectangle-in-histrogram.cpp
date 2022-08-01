#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1) {
            return heights[0];
        }
        stack<pair<int, int>> rect;
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (!rect.size() || heights[rect.top().first] <= heights[i]) {
                rect.push({i, heights[i]});
            } else {
                int curr_idx = i;
                while (rect.size() && rect.top().second > heights[i]) {
                    curr_idx = rect.top().first;
                    max_area = max(max_area, rect.top().second*(i-curr_idx));
                    rect.pop();
                }
                rect.push({curr_idx, heights[i]});
            }
        }
        while (!rect.empty()) {
            int idx = rect.top().first;
            int area = rect.top().second*(heights.size() - idx);
            max_area = max(max_area, area);
            rect.pop();
        }
        return max_area;
    }
};