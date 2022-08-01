#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> ordered_queries;
        for (int i = 0; i < queries.size(); i++) {
            ordered_queries.push_back({queries[i], i});
        }
        sort(ordered_queries.begin(), ordered_queries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans (queries.size(), -1);
        int previous_idx = 0;
        for (int i = 0 ; i < ordered_queries.size(); i++) {
            for (int j = previous_idx; j < intervals.size(); j++) {
                if (intervals[j][1] >= ordered_queries[i].first && intervals[j][0] <= ordered_queries[i].first) {
                    int interval_size = intervals[j][1] - intervals[j][0] + 1;
                    pq.push({interval_size, intervals[j][1]});
                } else if (intervals[j][0] > ordered_queries[i].first) {
                    previous_idx = j;
                    break;
                }
            }
            while (!pq.empty() && pq.top().second < ordered_queries[i].first) {
                pq.pop();
            }
            if (pq.size()) {
                ans[ordered_queries[i].second] = pq.top().first;
            }
        }
        return ans;
    }
};