#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isalphanum(char c) {
        return ((int(c) >= int('A')) && (int(c) <= int('Z'))) || ((int(c) >= int('a')) && (int(c) <= int('z'))) || ((int(c) >= int('0')) && (int(c) <= int('9')));
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalphanum(s[left])) {
                left++;
            }
            while (left < right && !isalphanum(s[right])) {
                right--;
            }
            if (char(tolower(s[left])) != char(tolower(s[right]))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};