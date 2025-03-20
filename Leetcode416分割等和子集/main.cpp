//
// Created by 橙子味 on 2025/3/20.
// 写了1h多，还看了题解，背包问题求解不熟练，边界与特殊情况处理不熟练，要重做一遍。。。代码写的狗屎
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for_each(nums.begin(), nums.end(), [&sum](int x){sum+=x;});
        if (sum % 2 != 0) return false;
        if (nums.size()<=1) return false;
        sum /= 2;
        //转化成0-1背包问题，区别在于要让背包内物品重量恰好等于sum
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, 0));
        for(int i = 0; i<nums.size(); ++i){
            dp[i][0] = true;
            if (nums[i] > sum) return false;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 1; j <= sum; ++j){
                if(j>=nums[i] && dp[i-1][j-nums[i]] == true){
                    dp[i][j] = true;
                    // cout<<i<<'\t'<<j<<endl;
                    if (j == sum)   return true;
                }
                else if(dp[i-1][j] == true) dp[i][j] = true;
            }
        }
        return false;
    }
};
// int main()
// {
//     auto cmp = [](int x, int y){return x>y;};
//     vector<int> vec = {1,2,3,4,5,6,7,8,9, 2,2,2};
//     priority_queue<int ,vector<int>, decltype(cmp)> heap(cmp);
//     heap.push(vec[0]);
//
//     int sum = 0;
//     auto l = [sum](int x)mutable {sum += x; return sum;};
//     int find_num = 20;
//     auto fd = find_if(vec.begin(), vec.end(), [find_num](int x){return x == find_num;});
//     cout<<(fd == vec.end())<<endl;
//
//     for_each(vec.begin(), vec.end(), [&sum](int i){sum += i; });
//     cout<<sum<<endl;
//
//
//
//     auto res = for_each(vec.begin(), vec.end(), l);
//     cout<<res(1)<<endl;
//
// }