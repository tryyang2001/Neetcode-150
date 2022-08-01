#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int curr_max = 1;
        int curr_min = 1;
        int max_product = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int temp = curr_max;
                curr_max = curr_min;
                curr_min = temp;
            }
            curr_min = (nums[i] < curr_min * nums[i])? nums[i] : curr_min * nums[i];
            curr_max = (nums[i] > curr_max * nums[i])? nums[i] : curr_max * nums[i]; 
            //cout << curr_min << " ... " << curr_max << endl;
            max_product = (max_product > curr_max)? max_product : curr_max;
        }
        return max_product;
    }
};