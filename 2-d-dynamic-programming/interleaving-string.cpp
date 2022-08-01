#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> dp;
    
    bool dfs(string s1, string s2, string s3, int i, int j) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }    
        if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()) {
            return dp[i][j];
        }
        if (i < s1.size() && s1[i] == s3[i + j] && dfs(s1, s2, s3, i + 1, j)) {
            return true;
        }
        if (j < s2.size() && s2[j] == s3[i + j] && dfs(s1, s2, s3, i, j + 1)) {
            return true;
        }
        dp[i][j] = false;
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return dfs(s1, s2, s3, 0, 0);
    }
};