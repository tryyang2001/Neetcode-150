#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};