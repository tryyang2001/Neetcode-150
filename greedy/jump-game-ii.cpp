#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size() - 1) {
            int farthest = 0; 
            for (int i = left; i <= right; i++) {
                farthest = (nums[i] + i > farthest)? nums[i] + i : farthest; //farthest possible position reachable from current position, will go to the position that has the largest index within the range
            }
            left = right + 1;
            right = farthest;
            count++;
        }
        return count;
    }
};