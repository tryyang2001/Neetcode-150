#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int i = 0; i <= n; i++) {
            //count number of 1 for each i in binary
            int count = 0;
            for (int j = 0; j < 17; j++) {
                int mask = 1 << j;
                if ((i & mask) == 0) {
                    continue;
                }
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};