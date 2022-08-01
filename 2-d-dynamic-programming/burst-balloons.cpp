#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    
    int dfs(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {
        if (left > right) {
            return 0; //nothing to pop
        }
        if (dp[left][right] > 0) {
            return dp[left][right];
        }
        for (int i = left; i <= right; i++) {
            int coin = nums[left-1] * nums[i] * nums[right+1];
            coin += dfs(nums, left, i - 1, dp) + dfs(nums, i + 1, right, dp);
            dp[left][right] = max(dp[left][right], coin);            
        }
        return dp[left][right];
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), 0));
        return dfs(nums, 1, nums.size() - 2, dp); //don't include the fake balloons
    }
};