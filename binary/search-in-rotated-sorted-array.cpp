#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //first find the changing position, then do two binary search in two sorted array
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            //case for left portion
            if (nums[start] <= nums[mid]) {
                //determines whether mid is in left or right portion
                if (nums[mid] < target || nums[start] > target) {
                    //search through remaining right
                    start = mid + 1;
                } else {
                    //current nums[mid] > target && nums[start] < target 
                    end = mid - 1;
                }
            }
            //case for right portion, when nums[start] >= nums[mid]
            else {
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};