#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //TC: O(n), Space: O(n)
        unordered_map<int, int> num_dict = {};
        for (int i = 0; i < nums.size(); i++) {
            if (num_dict.find(target - nums[i]) != num_dict.end()) {
                return {num_dict[target - nums[i]], i};
            }
            num_dict[nums[i]] = i;
        }
        return {};
    }
};