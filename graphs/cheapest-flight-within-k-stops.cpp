#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create adjacency list
        unordered_map<int, vector<pair<int, int>>> travel_from;
        for (auto& flight : flights) {
            travel_from[flight[0]].push_back({flight[2], flight[1]});
            if (travel_from.find(flight[1]) == travel_from.end()) {
                travel_from[flight[1]] = {};
            }
        }
        //create frontier and visited set
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> frontier;
        vector<int> visited(travel_from.size(), INT_MAX);
        vector<int> ans;
        frontier.push({-2, 0, src});
        while (!frontier.empty()) {
            auto& curr_vect = frontier.top();
            int curr_count = curr_vect[0] + 1;
            int cost = curr_vect[1];
            int curr = curr_vect[2];
            frontier.pop();
            //cout << "Curr: " << curr << " count: " << curr_count << " cost: "<< cost << endl;
            visited[curr] = (cost < visited[curr])? cost : visited[curr];
            if (curr == dst && curr_count <= k) {
                ans.push_back(cost);
            }
            for (auto& next : travel_from[curr]) {
                if (visited[next.second] < next.first + cost) {
                    continue;
                }
                frontier.push({curr_count, next.first + cost, next.second});
            }
        }
        if (ans.size() == 0) {
            return -1;
        }
        int total_cost = ans[0];
        for (auto& cost : ans) {
            if (cost < total_cost) {
                total_cost = cost;
            }
        }
        return total_cost;
    }
};