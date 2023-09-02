#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        }
        // path用于存储当前路径，res用于存储所有路径
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
};
// @lc code=end

