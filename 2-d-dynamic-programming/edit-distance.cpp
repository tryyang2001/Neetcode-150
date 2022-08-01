#include <vector>
#include <string>
#include <utility>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (!word1.size() && !word2.size()) {
            return 0;
        }
        if (!word1.size()) {
            return word2.size();
        }
        if (!word2.size()) {
            return word1.size();
        }
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));   
        for (int i = 0; i < dp.size(); i++) {
            dp[i][dp[i].size()-1] = word1.size() - i;
        }
        for (int i = 0; i < dp[0].size(); i++) {
            dp[dp.size()-1][i] = word2.size() - i;
        }
        for (int i = word1.size() - 1; i >= 0; i--) {
            for (int j = word2.size() - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    //take the min of insert(i, j+1), delete(i+1,j) and replace(i+1,j+1) and plus one for 1 extra operation
                    dp[i][j] = min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]) + 1;
                }
            }
        }
        /*for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        return dp[0][0];
    }
};