#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> p;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size(), 0);
        priority_queue<p, vector<p>, greater<p>> temp_idx;
        for (int i = 0; i < temperatures.size(); i++) {
            temp_idx.push(make_pair(temperatures[i], i));
            if (temp_idx.size() > 1) {
                while (temp_idx.top().first < temperatures[i]) {
                    days[temp_idx.top().second] = i - temp_idx.top().second;
                    temp_idx.pop();
                }
            } 
        }
        return days;
    }
};