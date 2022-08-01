#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<bool, int>> profit_table;
    
    int dfs(vector<int>& prices, int idx, bool buying) {
        if (idx >= prices.size()) {
            return 0;
        }
        if (profit_table.find(idx) != profit_table.end() && profit_table[idx].find(buying) != profit_table[idx].end()) {
            return profit_table[idx][buying];
        }
        if (buying) {
            int buy = dfs(prices, idx + 1, !buying) - prices[idx];
            int cooldown = dfs(prices, idx + 1, buying);
            profit_table[idx][buying] = max(buy, cooldown);
        } else {
            int sell = dfs(prices, idx + 2, !buying) + prices[idx];
            int cooldown = dfs(prices, idx + 1, buying);
            profit_table[idx][buying] = max(sell, cooldown);
        }
        return profit_table[idx][buying];
    }
    
    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, true);
    }
};