//
// Created by 橙子味 on 2025/3/18.
// 看了题解，核心思想主要是仅需记录最大和最小即可
// 优化：可以只需维护一个滚动的变量，而非整个dp数组，有待下次刷题优化
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.size() == 0 ) return 0;
    vector<int> max_dp(nums.size(), 0);
    vector<int> min_dp(nums.size(), 0);
    max_dp[0] = nums[0];
    min_dp[0] = nums[0];
    int max_res =  nums[0];
    for(int i = 1; i < nums.size(); ++i){
        int j = i-1;
        int t_max =  max(max(max_dp[j]*nums[i], min_dp[j]*nums[i]), nums[i]);
        int t_min = min(min(max_dp[j]*nums[i],min_dp[j]*nums[i]), nums[i]);
        if(max_dp[i] < t_max)   max_dp[i] = t_max;
        if(min_dp[i] > t_min)   min_dp[i] = t_min;
        max_res = max(max_res, max_dp[i]);

    }
    return max_res;
}
