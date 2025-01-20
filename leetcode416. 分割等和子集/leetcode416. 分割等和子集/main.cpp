//
//  main.cpp
//  leetcode416. 分割等和子集
//
//  Created by 陈梓玮 on 2022/8/9.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;



//爆搜超时
// bool canPartition(vector<int>& nums) {
//     int partition_sum = 0;
//     for(auto it : nums) partition_sum+=it;
//     if (partition_sum % 2 != 0) return false;
//     partition_sum /= 2;

//     list<int> partial_sum;
//     for(auto it1 : nums){
//         int size = partial_sum.size();
//         for(auto it2 = partial_sum.begin(); size>0; --size){
//             if(*it2+it1 == partition_sum)    return true;
// //            else if(*it2+it1 > partition_sum)
// //                it2 = partial_sum.erase(it2);
//             partial_sum.push_back(*it2+it1);
//             ++it2;
//         }
//         if(it1 == partition_sum)    return true;
//         partial_sum.emplace_back(it1);
//     }
//     return false;
// }
// 这个dp写的太臭了 5.03%4.98%
// bool canPartition(vector<int>& nums) {
//     int  t= 0, ele_max = -55;
//     for(auto it : nums) {t+=it; ele_max = max(it, ele_max);}
//     if(t%2 != 0)  return false;
//     const int sum= t / 2;
//     if(ele_max > sum)   return false;

//     vector<vector<int>>dp(nums.size()+1, vector<int>(sum, 0));
//     if(nums[0] == sum)   return true;
//     if(nums[0]<sum)
//         for(int i = 0; i < dp.size();++i)
//             dp[i][nums[0]] = 1;
//     for(int i = 1; i < nums.size(); ++i){
//         if(nums[i] == sum)  return true;
//         if(nums[i]<sum)
//             dp[i][nums[i]] = 1;
//         for(int j = 0; j < dp[i].size(); ++j){
//             if(dp[i-1][j] == 1){
//                 if(j + nums[i] == sum)  return true;
//                 if(j + nums[i] < sum){
//                     for(int x = i; x < nums.size()+1; ++x)
//                         dp[x][j + nums[i]] = 1;
//                 }
//             }
//         }
//     }
//     return false;
// }
// 优化后的
bool canPartition(vector<int>& nums) {
    if(nums.size()<2)   return false;
    int sum = 0, ele_max = INT_MIN;
    for(auto it:nums){  sum+=it;    ele_max = max(ele_max, it);}
    if(sum%2!=0)    return false;
    int target = sum/2;
    if(target<ele_max)return false;
    if(target == ele_max) return true;
    vector<vector<int>> dp(nums.size(),vector<int>(target, 0));

    dp[0][nums[0]] = 1;
    for(int i = 1; i < dp.size() ; ++i){
        for(int j = 0; j < dp[i].size(); ++j){
            if(dp[i-1][j] == 1){
                dp[i][j] = 1;
                if(j+nums[i]<target){
                    dp[i][j+nums[i]] = 1;
                }
                else if(j+nums[i]==target) return true;
            }
        }
    }
    return false;
}
int main()
{
    try {
        vector<int> v{20,10,9,8,8,3};
        cout<<canPartition(v)<<endl;
        
    } catch (exception e) {
        cout<<e.what()<<endl;
    }

}
//class add
//{
//public:
//    void operator()(int& l,const int& r)const{ l+=r;}       //求和
//};
//
//
//
//int main(int argc, const char * argv[]) {
//    std::vector<int>v{1,3,5,2};
//    int partition_sum = 0;
//
//    auto f = bind(add(), std::ref(partition_sum), std::placeholders::_1);
//    std::for_each(v.begin(), v.end(), f);
//    std::cout<<partition_sum<<std::endl;
//
//
//    partition_sum = 0;
//    auto l = [&](int x){partition_sum+=x;};
//    std::for_each(v.begin(), v.end(), l);
//    std::cout<<partition_sum<<std::endl;
//    return 0;
//}
