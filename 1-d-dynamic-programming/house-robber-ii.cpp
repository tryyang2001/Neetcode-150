#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums[0];
        }
        int profit1 = 0;
        int curr_max = 0;
        int prev_max = 0;
        //can either rb house[0] to house[n-2] or house[1] to house[n-1]
        for (int i = 0; i < nums.size() - 1; i++) {
            int temp = (nums[i] + prev_max > curr_max)? nums[i] + prev_max : curr_max;
            prev_max = curr_max;
            curr_max = temp;
        }
        profit1 = curr_max;
        curr_max = 0;
        prev_max = 0;
        for (int i = 1; i < nums.size(); i++) {
            int temp = (nums[i] + prev_max > curr_max)? nums[i] + prev_max : curr_max;
            prev_max = curr_max;
            curr_max = temp;
        }
        return (profit1 > curr_max)? profit1 : curr_max;
    }
};