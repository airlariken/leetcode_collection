//
// Created by 橙子味 on 2025/3/19.
// 需要再刷
// 看了题解，第一遍还是写错，应该维护一个类似栈的空间存储访问的元素，随着dfs深入插入元素，退出dfs则弹出元素，配合visit数组
#include <vector>
using namespace std;

class Solution {
    vector<bool> visited;
    vector<vector<int>> res;
    vector<int> one_res;
public:
    void dfs(const vector<int> &nums){
        if (one_res.size() == nums.size())  res.emplace_back(one_res);
        for(int i = 0; i < nums.size(); ++i){
            if (visited[i] == false){
                one_res.emplace_back(nums[i]);
                visited[i] = true;
                dfs(nums);
                one_res.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), 0);
        dfs(nums);
        return res;
    }
};