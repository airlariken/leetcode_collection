//
// Created by 橙子味 on 2025/3/19.
// 莫名其妙好像就过了哈哈，虽然时间复杂度好像排名很后，和46题的全排列很类似，甚至不需要visited数组
// 复盘回头想了下，看了下评论区也有类似解法，应该是一个巧妙的树结构，仅访问比他大的节点，而且每次访问到后都存储当前为止的访问路径栈
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> single_res;
public:
    void dfs(int cur_pos, vector<int> &nums){
        res.emplace_back(single_res);
        for(int i = cur_pos; i<nums.size(); ++i){
            single_res.emplace_back(nums[i]);
            dfs(i+1, nums);
            single_res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};