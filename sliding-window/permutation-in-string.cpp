#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_count(26, 0);
        for (auto& c : s1) {
            s1_count[int(c - 'a')]++;
        }
        int left_limit = 0;
        int right_limit = s2.size() - 1;
        int left = left_limit;
        int right = s1.size() - 1 + left;
        while (right <= right_limit) {
            left = left_limit;
            int matches = 26;
            vector<int> s2_count(26, 0);
            while (left <= right) {
                s2_count[int(s2[left++]-'a')]++;
            }
            for (int i = 0; i < 26; i++) {
                if (s2_count[i] != s1_count[i]) {
                    matches--;
                }
            }
            //cout << matches << endl;
            if (matches == 26) {
                return true;
            }
            left_limit++;
            right = s1.size() - 1 + left_limit;
        }
        return false;
    }
};