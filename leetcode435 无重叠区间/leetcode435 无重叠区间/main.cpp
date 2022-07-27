//
//  main.cpp
//  leetcode435 无重叠区间
//
//  Created by 陈梓玮 on 2022/7/23.
//
// https://leetcode.cn/problems/non-overlapping-intervals/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct comp{
    bool operator()(const vector<int>& v1, const vector<int>& v2){        //降序排列
        if(v1[1]<v2[1])
            return true;
        return false;
    }
};
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp());
    int erase_num = 0;
    int cur_end = (*intervals.begin())[1];
    for(int i = 1; i< intervals.size(); ++i){
        // cout<<intervals[i][0]<<'\t'<<intervals[i][1]<<endl;
        if (intervals[i][0] < cur_end)
            ++erase_num;
        else{
            cur_end = intervals[i][1];  //更新当前位置
        }
    }
    
    return erase_num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> m_vec;
    
    std::cout << "Hello, World!\n";
    return 0;
}
