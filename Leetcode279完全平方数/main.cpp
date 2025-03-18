//
// Created by 橙子味 on 2025/3/17.
// 参考题解写的
#include <vector>
using std::vector;
int numSquares(int n) {
    vector<int> mem(n+1,0);
    mem[0] = 0;
    for (int i = 1; i <= n; ++i){
        int min_cnt = INT_MAX;
        for (int j = 1; j * j <= i; ++j){
            if (min_cnt > mem[i-j*j])
                min_cnt = mem[i-j*j];
        }
        mem[i] = min_cnt+1;
    }
    return mem[n];
}

