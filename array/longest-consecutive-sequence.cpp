#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto& n : nums) {
            if (num_set.find(n) == num_set.end()) {
                num_set.insert(n);
            }
        }
        int max_count = 0;
        for (auto& n : nums) {
            if (num_set.find(n-1) == num_set.end()) {
                int count = 1;
                while (num_set.find(n+count) != num_set.end()) {
                    count++;
                }
                if (count > max_count) {
                    max_count = count;
                }
            }
        }
        return max_count;
    }
};