#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int curr_max = 0; //before + nums[i], it stores the current possible max profit
        int prev_max = 0; //stores previous max profit that is obtainable from houses that will not trigger the security system
        for (int i = 0; i < nums.size(); i++) {
            int temp = (nums[i] + prev_max > curr_max)? nums[i] + prev_max : curr_max;
            prev_max = curr_max;
            curr_max = temp;
        }
        return curr_max;
    }
};