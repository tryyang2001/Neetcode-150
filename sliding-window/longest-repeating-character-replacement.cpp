#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        int left = 0;
        int max_freq = 0;
        unordered_map<char, int> count;
        count[s[0]]++;
        for (int right = 1; right < s.size(); right++) {
            count[s[right]]++;
            max_freq = (count[s[right]] > max_freq)? count[s[right]] : max_freq;
            int length = right - left + 1;
            while (length - max_freq > k) {
                count[s[left]]--;
                left++;
                length = right - left + 1;
            }
            longest = (length > longest)? length : longest;
        }
        return longest;
    }
};