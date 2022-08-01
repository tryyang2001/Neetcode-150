#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for (int i = 0; i < s.size(); i++) {
             last[s[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            int limit = last[s[i]];
            for (int j = i; j < limit; j++) {
                if (last[s[j]] > limit) {
                    limit = last[s[j]];
                }
            }
            ans.push_back(limit + 1 - i);
            i = limit;
        }
        return ans;
    }
};