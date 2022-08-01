using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int sum_bit = 0;
        int carry = 0;
        while (b != 0) {
            sum_bit = a ^ b;
            carry = (unsigned int)(a & b) << 1; //so that additional carry bit can be triggered
            a = sum_bit;
            b = carry;
        }
        return a;
    }
};