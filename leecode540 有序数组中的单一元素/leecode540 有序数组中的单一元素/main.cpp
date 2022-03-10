//
//  main.cpp
//  leecode540 有序数组中的单一元素
//
//  Created by 陈梓玮 on 2022/2/14.
//

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 0)
        return 0;
        //解题思路
    //剩余子序列为偶数则是带中间数的一侧有问题
    //奇数则为不带中间数的一侧有问题
    int l = 0, r = nums.size()-1;
    int mid = (nums.size()-1)/2;
    int next = nums[mid+1], behind = nums[mid-1];//要判断越界没
    while(l < r) {
        if (mid == r || nums[mid+1] != nums[mid])       //边缘或与右侧不同
            if(mid == l ||  nums[mid-1] != nums[mid])   //边缘或与左侧不同
                return nums[mid];       //如果mid是孤立元素
        if ((mid-l) % 2 == 0){          //偶数情况
            if (nums[mid+1] == nums[mid]){
                l = mid + 2;            //跳过中间数以及与其相同的另一个数
            }
            else {
                r = mid - 2;            //跳过中间数以及与其相同的另一个数
            }
            mid = (l + r ) / 2;
        }
        else{                           //奇数情况
            if (nums[mid+1] == nums[mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            mid = (l + r ) / 2;
        }
    }
    if (l == r)
        return nums[mid];
    return 0;
}
    
int main(int argc, const char * argv[]) {
    
    vector<int> v{1,2,2,3,3};
    cout<<singleNonDuplicate(v)<<endl;
    return 0;
}
