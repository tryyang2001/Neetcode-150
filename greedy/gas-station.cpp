#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 1) < accumulate(cost.begin(), cost.end(), 1)) {
            return -1;
        }
        int total = 0;
        int best_starting = 0;
        //don't care about circular path since solution is guaranteed
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            if (total < 0) {
                total = 0;
                best_starting = i + 1; //this will never exceed gas.size()
            }
        }
        return best_starting;
    }
};