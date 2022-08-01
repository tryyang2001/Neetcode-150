#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        vector<int> ans;
        deque<int> window; //push index instead of value
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            while (window.size() && nums[window.back()] < nums[right]) {
                window.pop_back();
            }
            window.push_back(right);
            if (left > window.front()) {
                window.pop_front();
            }
            if (right + 1 >= k) {
                ans.push_back(nums[window.front()]);
                left++;
            }            
            right++;
        }
        return ans;
    }
};