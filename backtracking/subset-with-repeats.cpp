#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& curr, int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            vector<int> new_curr(curr);
            ans.push_back(new_curr);
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(curr, idx + 1, nums);
        curr.pop_back();
        while (idx < nums.size() - 1 && nums[idx+1] == nums[idx]) {
            idx++;
        }
        backtrack(curr, idx + 1, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        //need n sets to makes sure it does not repeat
        backtrack(curr, 0, nums);
        return ans;
    }
};