#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> explored;
        int curr = n;
        while (explored.find(curr) == explored.end()) {
            explored.insert(curr);
            int sum = 0;
            while (curr > 0) {
                sum += (curr % 10) * (curr % 10);
                curr /= 10;
            }
            curr = sum;
            if (curr == 1) {
                return true;
            }
        }
        return false;
    }
};