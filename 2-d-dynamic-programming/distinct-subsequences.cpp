#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;
    int dfs(string& s, string& t, int i, int j) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()) {
            return dp[i][j];
        }
        //choose include and not include
        if (s[i] == t[j]) {
            dp[i][j] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
        } else {
            dp[i][j] = dfs(s, t, i + 1, j);
        }
        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        return dfs(s, t, 0, 0);
    }
};