#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //Use unordered_set, O(n) extra space, O(n) time complexity
        unordered_set<int> num_set = {};
        for (auto& n : nums) {
            if (num_set.find(n) == num_set.end()) {
                num_set.insert(n);
            } else {
                return true;
            }
        }
        return false;
    }
};