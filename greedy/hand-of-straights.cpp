#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> dp;
        for (auto& n : hand) {
            dp[n]++;
        }
        priority_queue<int, vector<int>, greater<int>> card;
        for (auto& n : dp) {
            card.push(n.first);
        }
        while (!card.empty()) {
            int curr_min = card.top();
            dp[curr_min]--;
            if (dp[curr_min] == 0) {
                card.pop();
            }
            int i = 1;
            while (i < groupSize) {
                if (dp.find(curr_min + i) == dp.end()) {
                    return false;
                } else {
                    dp[curr_min + i]--;
                    if (dp[curr_min+i] == 0) {
                        if (card.top() != curr_min + i) {
                            return false;
                        } else {
                            card.pop();
                        }
                    }
                }
                i++;
            }
        }
        return true;
    }
};