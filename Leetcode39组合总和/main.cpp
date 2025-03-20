//
// Created by 橙子味 on 2025/3/20.
// 几乎一模一样的模板套路，实际上还能优化剪枝
#include <vector>
using std::vector;
class Solution {
    vector<vector<int>> res;
    vector<int> single_res;
    int single_res_sum = 0;
public:
    void dfs(vector<int> &candidates, int pos, int target){
        // cout<<"访问sum为:"<<single_res_sum<<'\t';
        if (single_res_sum > target) return;
        if(single_res_sum == target) {res.emplace_back(single_res); return;}
        for(int i = pos; i < candidates.size() ; ++i){
            single_res.emplace_back(candidates[i]);
            single_res_sum += candidates[i];
            dfs(candidates, i, target);
            single_res.pop_back();
            single_res_sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0,target);
        return res;
    }
};