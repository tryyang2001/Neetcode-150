#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        int max_freq = 0;
        for (auto& n : nums) {
            num_freq[n] += 1;
            if (num_freq[n] > max_freq) {
                max_freq = num_freq[n];
            }
        }
        vector<vector<int>> freq_to_num(max_freq + 1);
        for (auto& n : num_freq) {
            freq_to_num[n.second].push_back(n.first);
        }
        vector<int> ans;
        ans.reserve(k);
        for (int i = max_freq; i >= 0 && ans.size() < k; i--) {
            for (auto& n : freq_to_num[i]) {
                ans.push_back(n);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};