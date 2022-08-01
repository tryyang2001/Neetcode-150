#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) {
            return false;
        }
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        int target = sum / 2;
        unordered_set<int> dp;
        dp.insert(0); //don't add anything at all
        for (int i = nums.size() - 1; i >= 0; i--) {
            //for each number, can choose between add and don't add
            unordered_set<int> next_dp;
            for (auto& n : dp) {
                next_dp.insert(nums[i] + n);
            }
            if (next_dp.find(target) != next_dp.end()) {
                return true;
            }
            for (auto& n : next_dp) {
                dp.insert(n);
            }
        }
        return false;
    }
};