#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max = nums[0];
        int curr_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_max = (nums[i] > curr_max + nums[i])? nums[i] : curr_max + nums[i];
            max = (max > curr_max)? max : curr_max;
        }
        return max;
    }
};