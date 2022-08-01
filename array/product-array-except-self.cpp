#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int max_product = 1;
        int zero_count = 0;
        for (auto& n : nums) {
            if (n == 0) {
                zero_count++;
                if (zero_count > 1) {
                    vector<int> all_zeros(nums.size(), 0);
                    return all_zeros;
                }
                continue;
            }
            max_product *= n;
        }
        vector<int> ans;
        ans.reserve(nums.size());
        if (zero_count > 0) {
            for (auto& n : nums) {
                if (n == 0) {
                    ans.push_back(max_product);
                } else {
                    ans.push_back(0);
                }
            }
            return ans;
        }
        for (auto& n : nums) {
            ans.push_back(max_product / n);
        }
        return ans;
    }
};