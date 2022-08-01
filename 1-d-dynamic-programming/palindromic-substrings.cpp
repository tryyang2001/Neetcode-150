#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            //find all possible odd length palindrome
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            //find all possible even length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};