#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            if (nums[start] < nums[end]) {
                min = (min < nums[start])? min : nums[start];
                break;
            }
            int mid = (start + end) / 2;
            min = (min < nums[mid])? min : nums[mid];
            if (nums[start] <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return min;
    }
};