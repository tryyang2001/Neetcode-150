#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto& n : nums) {
            ans ^= n;
        }
        return ans;
    }
};