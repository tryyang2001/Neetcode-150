#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void bfs(vector<int>& curr, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MIN) {
                continue;
            }
            curr.push_back(nums[i]);
            int original = nums[i];
            nums[i] = INT_MIN;
            bfs(curr, nums);
            curr.pop_back();
            nums[i] = original;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            ans.push_back(nums);
            return ans;
        }
        vector<int> curr;
        curr.reserve(nums.size());
        bfs(curr, nums);
        return ans;
    }
};