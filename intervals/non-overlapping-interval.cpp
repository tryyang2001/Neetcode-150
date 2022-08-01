#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i+1][0]) {
                count++;
                intervals[i+1][0] = intervals[i][1];
                intervals[i+1][1] = min(intervals[i][1], intervals[i+1][1]);
            } 
        }
        return count;
    }
};