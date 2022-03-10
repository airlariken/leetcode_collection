//
//  main.cpp
//  leetcode2104 子数组范围和
//
//  Created by 陈梓玮 on 2022/3/4.
//

#include <iostream>
#include <vector>
using namespace std;

//未解决

vector<int> f(int n){
    vector<int> add;
    for(int i = 0; i < n; ++i) {
        add.push_back(2*i-(n-1));
//        cout<<2*i-(n-1)<<'\t'<<endl;
    }
    return add;
}
long long subArrayRanges(vector<int>& nums)
{
    vector<int> add = f(nums.size());
    int res = 0;
    for(int i = 0; i < nums.size(); ++i){
        res += nums[i]*add[i];
        cout<<nums[i]*add[i]<<endl;
    }

    return res;
    
}

int main(int argc, const char * argv[]) {
    vector<int> v{1,2,3};
    cout<<subArrayRanges(v)<<endl;
    return 0;
}
