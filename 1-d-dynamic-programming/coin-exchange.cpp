#include <vector>
using namespace std;

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        //O(amount*len(coins)), with O(amount) extra space
        vector<int> dp(amount+1, amount+1); //initialize dp of size amount+1 and with values amount+1 which indicates that that amount cannot be made up by any combination of the coins
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto& c : coins) {
                if (i - c >= 0) {
                    if (1 + dp[i-c] < dp[i]) {
                        dp[i] = 1 + dp[i-c];
                    }
                }
            }
        }
        return (dp[amount] != amount + 1)? dp[amount] : -1;
    }
};