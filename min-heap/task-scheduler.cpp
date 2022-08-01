#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskcount;
        for (int i = 0; i < tasks.size(); i++) {
            taskcount[tasks[i]]++;
        }
        priority_queue<int> pq;
        int count = 0;
        for (auto& task : taskcount) {
            pq.push(task.second);
        }
        queue<pair<int, int>> unavailables;
        while (!pq.empty() || !unavailables.empty()) {
            count++;
            if (!pq.empty()) {
                int curr_task_remaining = pq.top() - 1;
                pq.pop();
                if (curr_task_remaining > 0) {
                    unavailables.push(make_pair(curr_task_remaining, count + n));
                }
            }
            if (!unavailables.empty() && unavailables.front().second == count) {
                pq.push(unavailables.front().first);
                unavailables.pop();
            }
        }
        return count;
    }
};