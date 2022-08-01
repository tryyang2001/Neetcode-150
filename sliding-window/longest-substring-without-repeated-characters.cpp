#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_set<char> char_set;
        int left = 0;
        //O(n) since only loop through once
        for (int right = 0; right < s.size(); right++) {
            while(char_set.find(s[right]) != char_set.end()) {
                char_set.erase(s[left++]);
            }
            char_set.insert(s[right]);
            if (char_set.size() > longest) {
                longest = char_set.size();
            }
        }
        return longest;
    }
};