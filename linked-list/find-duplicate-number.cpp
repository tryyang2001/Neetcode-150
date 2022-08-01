#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        //1st phase, fast will jump twice while slow jumps once, stop when interseciont is found
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        fast = 0;
        //2nd phase, both fast and slow jump once each time, and stop when intersection is found
        while (1) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast) {
                return slow; //the ans here guarantees it is the start of a cycle in a linked list
            }
        }
        return -1;
    }
};