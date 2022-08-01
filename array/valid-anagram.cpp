#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> char_freq(26, 0);
        for (auto& c : s) {
            char_freq[int(c) - int('a')]++;
        }
        for (auto& c : t) {
            char_freq[int(c) - int('a')]--;
        }
        for (auto& i : char_freq) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};