#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //math approach
        /*int arithmetic_sum = (nums.size() * (nums.size() + 1)) / 2;
        for (auto& num : nums) {
            arithmetic_sum -= num;
        }
        return arithmetic_sum;*/
        //bit manipulation approach
        int ans = 0;
        for (int i = 0; i <= nums.size(); i++) {
            ans ^= i;
        }
        for (auto& n : nums) {
            ans ^= n;
        }
        return ans;
    }
};