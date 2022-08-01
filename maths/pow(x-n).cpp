#include <math.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return double(1);
        } else if (x == 0) {
            return 0;
        } else if (x == 1) {
            return 1;
        }
        double ans = 1;
        if (n < 0) {
            x = 1/x;
            n = abs(n);
        }         
        while (n) {
            if (n % 2) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }     
        return ans;
    }
};