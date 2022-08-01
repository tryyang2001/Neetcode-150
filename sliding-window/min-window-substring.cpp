#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        unordered_map<char, int> t_count;
        for (auto& c : t) {
            t_count[c]++;
        }
        int need = t_count.size();
        unordered_map<char, int> s_count;
        int have = 0;
        vector<int> ans_index (2);
        ans_index[0] = -100000;
        ans_index[1] = 100000;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (t_count.find(s[right]) != t_count.end()) {
                s_count[s[right]]++;
                if (s_count[s[right]] == t_count[s[right]]) {
                    have++;
                }
                if (have == need) {
                    while (have == need) {
                        if (s_count.find(s[left]) != s_count.end()) {
                            s_count[s[left]]--;
                            if (s_count[s[left]] < t_count[s[left]]) {
                                have--;
                            }
                            if (right - left < ans_index[1] - ans_index[0]) {
                                ans_index[0] = left;
                                ans_index[1] = right;
                            } 
                        }
                        left++;
                    }
                }
            }
            right++;
        }
        if (ans_index[0] < 0) {
            return "";
        }
        string ans = "";
        for (int i = ans_index[0]; i <= ans_index[1]; i++) {
            ans += s[i];
        }
        return ans;
    }
};

