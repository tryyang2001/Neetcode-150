#include <math.h>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return x;
        }
        int sign = (x < 0)? -1 : 1;
        if (x == INT_MIN) {
            return 0;
        }
        x = abs(x);
        int digit_num = log10(x) + 1;
        int reverse = 0;
        for (int i = 0; i < digit_num; i++) {
            if (x % 10 * pow(10, digit_num - i - 1) < INT_MAX) {
                if (reverse + x % 10 * pow(10, digit_num - i - 1) > INT_MAX) {
                    return 0;
                }
                reverse += x % 10 * pow(10, digit_num - i - 1);
                x /= 10;
            } else {
                return 0;
            }
        }
        return reverse * sign;
    }
};