#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp; //first key is the idx, next key is the value
    int dfs(vector<int>& nums, int idx, int curr_sum, int target) {
        if (idx >= nums.size()) {
            if (curr_sum == target) {
                return 1;
            }
            return 0;
        }
        if (dp.find(idx) != dp.end() && dp[idx].find(curr_sum) != dp[idx].end()) {
            //do smth, dun dfs the same path again
            return dp[idx][curr_sum];
        }
        dp[idx][curr_sum] = dfs(nums, idx + 1, curr_sum + nums[idx], target) + dfs(nums, idx + 1, curr_sum - nums[idx], target);
        return dp[idx][curr_sum];
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int val = dfs(nums, 0, 0, target);     
        return val;
    } 
};