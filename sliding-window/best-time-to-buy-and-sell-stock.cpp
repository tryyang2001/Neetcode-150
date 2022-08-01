#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = 0;
        int sell = 1;
        while (sell < prices.size()) {
            //when to update buy time? - when there exists future buy < current buy
            //when to update sell time? - when there exists future sell > current sell
            if (prices[buy] > prices[sell]) {
                buy = sell;
            } else {
                int profit = prices[sell] - prices[buy];
                if (profit > max_profit) {
                    max_profit = profit;
                }
            }
            sell++;
        }
        return max_profit;
    }
};