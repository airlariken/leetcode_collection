//
// Created by 橙子味 on 2025/3/14.
//第一次没做出来，看了题解还是没做出来，最重要的去重环节很容易搞错
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i){
        if (i>0 && nums[i] == nums[i-1]) continue;
        int l = i+1, r = nums.size()-1;
        while(l < r) {
            int target = nums[l] + nums[r];
            if (target == -nums[i])  {
                res.push_back({nums[i], nums[l],nums[r]});
                --r; ++l;
                while(l < r && nums[l] == nums[l-1])    ++l;            //这里
                while(l < r && nums[r] == nums[r+1])    --r;            //这里
            }
            else if(target+nums[i]<0)  ++l;
            else    --r;
        }
    }
    return res;
}
