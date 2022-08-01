#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int total_cost = 0;
        cost.push_back(0);
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += (cost[i-1] < cost[i-2])? cost[i-1] : cost[i-2];
        }
        return cost[cost.size() - 1];
    }
};