#include <vector>
using namespace std;

class Solution {
public:
   void dfs(vector<vector<int>>& ans, vector<int>& curr, int idx, vector<int>& nums) {
       //cout << idx << endl;
       if (idx >= nums.size()) {
           vector<int> new_curr(curr);
           ans.push_back(new_curr);
           return;
       }
       //add current number
       curr.push_back(nums[idx]);
       dfs(ans, curr, idx + 1, nums);
       //don't add current number
       curr.pop_back();
       dfs(ans, curr, idx + 1, nums);
       return;
   }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans, curr, 0, nums);
        return ans;
    }
};