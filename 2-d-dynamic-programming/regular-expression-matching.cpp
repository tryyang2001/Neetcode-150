#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> dp;
    
    bool dfs(string& s, string & p, int i, int j) {
        if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()) {
            return dp[i][j];
        }
        if (i >= s.size() && j >= p.size()) {
            return true;
        }
        if (j >= p.size()) {
            return false;
        }
        bool matched = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j+1] == '*') {
            //choose if wanna use '*' or don't
            dp[i][j] = dfs(s, p, i, j + 2) || matched && dfs(s, p, i + 1, j); 
            return dp[i][j];
        }
        if (matched) {
            //simply go next if character matched
            dp[i][j] = dfs(s, p, i + 1, j + 1); 
            return dp[i][j];
        }
        dp[i][j] = false;
        return false;
    }
    
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
    }
};