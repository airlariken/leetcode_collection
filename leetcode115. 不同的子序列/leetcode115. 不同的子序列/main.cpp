//
//  main.cpp
//  leetcode115. 不同的子序列
//
//  Created by 陈梓玮 on 2022/8/1.
//

#include <iostream>
#include <vector>
using namespace std;

//自己想的
//核心思想在于状态装换条件，维护一个一维数组，该数组第i个元素表示以i结尾的字符串在原串的个数.
//dp[i]更新条件为遍历原串，对于原串的第j个元素，！！逆序！！遍历子串，检查到s[j] == t [j]则令dp[j] = dp[j] + dp[j-1]（上一次循环已经计算的结果加上以s[j]结尾的子串个数之和）
int numDistinct(string s, string t) {
    vector<long long int> dp(t.length(), 0);    //int就溢出了=、=
    for(int i = 0; i < s.length(); ++i){
        for(int j = t.length()-1; j >=0 ;--j){
            if(s[i] == t[j] && j >= 1 && i + (t.length()-j) <= s.length())  // 剪枝，否则中间结果会溢出
                dp[j] += dp[j-1];
            else if(s[i] == t[j] && j == 0)
                dp[j] += 1;
        }
    }
    return dp[t.length()-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
