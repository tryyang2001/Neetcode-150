#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (auto& word : wordDict) {
                if (i + word.size() <= s.size()) {
                    if (s.substr(i, word.size()) == word) {
                        dp[i] = dp[i + word.size()];
                    }
                    //exit the loop if a matched word is found
                    if (dp[i]) {
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};