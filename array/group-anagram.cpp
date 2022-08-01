#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for (auto& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            table[s].push_back(str);
        } 
        vector<vector<string>> ans;
        for (auto& s : table) {
            ans.push_back(s.second);
        }
        return ans;
    }
};