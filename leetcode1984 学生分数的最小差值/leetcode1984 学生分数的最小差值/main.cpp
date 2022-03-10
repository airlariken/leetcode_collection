//
//  main.cpp
//  leetcode1984 学生分数的最小差值
//
//  Created by 陈梓玮 on 2022/2/13.
//

#include <iostream>
#include <vector>
using namespace std;

void quicksort(int l, int r, vector<int>& num)
{
    int pivot = num[l];
    int start = l, end = r;
    while(l < r){
        while(l<=r && num[l]<=pivot){
            l++;
        }
        while(l<=r && num[r]>=pivot){
            r--;
        }
        if(l < r){
            int t = num[r];
            num[r] = num[l];
            num[l] = t;
        }
    }
    int t = num[r];
    num[r] = num[start];
    num[start] = t;
    if(r-1-start > 0)
        quicksort(start, r-1, num);
    if (end - (r+1) > 0)
        quicksort(r+1, end, num);
    return ;
}
//int minimumDifference(vector<int>& nums, int k) {
//
//}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v{4,9,1 , 5, 2};
    quicksort(0, v.size()-1, v);
    for (auto i : v)
        cout<<i<<'\t';
    std::cout << "Hello, World!\n";
    return 0;
}
