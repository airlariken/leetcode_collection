//
// Created by 橙子味 on 2025/3/17.
//
#include <vector>
using namespace std;

//自己写的在原数组滚动求解 ，空间复杂度O(1)
int my_rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size()==2) return max(nums[1], nums[0]);
    nums[2] = nums[2]+nums[0];
    if (nums.size() == 3) return max(nums[2], nums[1]);
    for(int i = 3; i < nums.size(); ++i){
        nums[i-2] = max(nums[i-2], nums[i-3]);
        nums[i] += nums[i-2];
    }
    return max(nums[nums.size()-1], nums[nums.size()-2]);
}

int rob(vector<int>& nums) {        //基于题解的dp数组求解，空间复杂度O(N)
    if (nums.empty()) {
        return 0;
    }
    int size = nums.size();
    if (size == 1) {
        return nums[0];
    }
    vector<int> dp(nums.size());
    dp [0] = nums[0];
    dp [1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[nums.size()-1];
}