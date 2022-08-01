#include <stdint.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i <= 31; i++){
            if((n & (1 << i)) != 0){
                ans = ans + (1 << (31 - i));
            }        
        }
        return ans;
        
    }
};