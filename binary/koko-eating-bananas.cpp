#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for (auto& p : piles) {
            max = (p > max)? p : max;
        }
        int start = 1;
        int end = max;
        int ans = max;
        while (start <= end) {
            int mid = (start + end) / 2;
            long total = 0; //precision!
            for (auto& p : piles) {
                total += ceil(p/double(mid)); //precision!
            }
            //cout << mid << " " << total << endl;
            if (total <= h) {
                ans = (mid < ans)? mid : ans;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};