#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int min_height = (height[left] < height[right])? height[left] : height[right];
            int curr_area = (right - left) * min_height;
            if (curr_area > max_area) {
                max_area = curr_area;
            } else {
                if (min_height == height[right]) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return max_area;
    }
};