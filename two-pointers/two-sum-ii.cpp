#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //1-indexed, ans need +1
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            while(numbers[left] + numbers[right] < target) {
                left++;
            }
            while (numbers[left] + numbers[right] > target) {
                right--;
            }
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};