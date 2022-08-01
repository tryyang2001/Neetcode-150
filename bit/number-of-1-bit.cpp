#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t mask = 1 << i;
            if ((n & mask) == 0) {
                continue;
            }
            count++;
        }
        return count;
    }
};