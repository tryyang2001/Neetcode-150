#include <vector>
using namespace std;

class Solution {
public:
    bool greedy_shift_goal(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
                if (nums[0] >= goal) {
                    return true;
                }
            }
        }
        return goal == 0;
    }
    
    /*bool dfs(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return false;
        }
        if (idx == nums.size() - 1) {
            return true;
        }
        if (visited.find(idx) != visited.end()) {
            return false;
        }
        visited.insert(idx);
        for (int i = nums[idx]; i > 0; i--) {
            bool result = dfs(nums, idx + i);
            if (result) {
                return true;
            }
        }
        return false;
    }*/
    
    bool canJump(vector<int>& nums) {
        return greedy_shift_goal(nums);
    }
};