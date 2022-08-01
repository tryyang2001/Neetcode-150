#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<char, string> phone_map;
    vector<string> ans;
    void initialize_phone_map() {
        phone_map['2'] = ("abc");
        phone_map['3'] = ("def");
        phone_map['4'] = ("ghi");
        phone_map['5'] = ("jkl");
        phone_map['6'] = ("mno");
        phone_map['7'] = ("pqrs");
        phone_map['8'] = ("tuv");
        phone_map['9'] = ("wxyz");
    }
    
    void dfs(string digits, int idx, string curr_str) {
        if (idx == digits.size()) {
            ans.push_back(curr_str);
            return;
        }
        for (auto& c : phone_map[digits[idx]]) {
            curr_str += c;
            dfs(digits, idx + 1, curr_str);
            curr_str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        initialize_phone_map();
        dfs(digits, 0, "");
        return ans;
    }
};