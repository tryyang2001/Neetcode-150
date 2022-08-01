#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        //O(n) solution
        unordered_map<int, int> dp; //dp stores the total possible decode count
        dp[s.size()] = 1; //last character has only 1 possible decode way
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
            }
            //if s[i:i+2] is within range 10-26, can have another decode way of two digits
            if (i + 1 < s.size() && stoi(s.substr(i, 2)) >= 10 && stoi(s.substr(i, 2)) <= 26){
                dp[i] += dp[i+2];
            }
        }
        return dp[0]; //decode way for all possibilities
    }
};