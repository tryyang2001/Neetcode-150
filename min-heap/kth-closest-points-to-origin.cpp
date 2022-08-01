#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push(make_pair(dist, i));
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k ;i++) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};