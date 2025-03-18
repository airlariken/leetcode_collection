//
// Created by 橙子味 on 2025/3/14.

#include <vector>
using namespace std;


int climbStairs(int n) {// 可以将备忘录改成滚动的，现在内存是O(N)
    vector<int> mem(n+1,0);
    mem[0] = 1;
    mem[1] = 1;
    for(int i = 2; i < n+1; ++i){
        mem[i] = mem[i-1] + mem[i-2];
    }
    return mem[n];
}
