#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int curr_idx = 0;
        unordered_set<int> check;
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
                continue;
            }
            for (int j = 0; j < target.size(); j++) {
                if (triplets[i][j] == target[j]) {
                    check.insert(j);
                }
            }
        }
        return check.size() == 3;
    }
};