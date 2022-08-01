#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size()-1] < 9) {
            digits[digits.size()-1]++;
            return digits;
        }
        vector<int> carry(digits.size() + 1, 0);
        digits[digits.size()-1] = 0;
        carry[digits.size() - 1] = 1;
        for (int i = digits.size() - 2; i >= 0; i--) {
            int curr_sum = digits[i] + carry[i+1];
            if (curr_sum > 9) {
                carry[i] = 1;
            }
            digits[i] = (curr_sum) % 10;
        }
        if (carry[0]) {
            for (int i = 0; i < digits.size(); i++) {
                carry[i+1] = digits[i];
            }
            return carry;
        }
        return digits;
    }
};