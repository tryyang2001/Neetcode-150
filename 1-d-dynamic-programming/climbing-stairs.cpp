#include <unordered_map>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> storage;
        storage[1] = 1;
        storage[2] = 2;
        for (int i = 3; i <= n; i++) {
            storage[i] = storage[i-1] + storage[i-2];
        }
        return storage[n];
    }
};