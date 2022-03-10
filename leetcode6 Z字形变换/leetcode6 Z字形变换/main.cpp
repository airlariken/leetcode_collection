//
//  main.cpp
//  leetcode6 Z字形变换
//
//  Created by 陈梓玮 on 2022/3/1.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 核心思想: 观察Z字型的数学关系
// 对于第一行和最后一行直接 + (numRows-1) * 2)个
// 对于中间行，元素间隔数量关系周期为2， 第一次跳 (numRows-(i+1))*2 个 第二次跳 (numRows -(numRows-i))*2个

string convert(string s, int numRows) {
    if (numRows == 1)   //特殊情况处理
        return s;
    string res = "";
    int cur = 0, len = s.length();
    for (int i = 0; i < numRows; ++i){
        // 读到第几行
        cur = i;
        bool flag = 1;
        while (cur < len) {
            res += s[cur];
            if(i == numRows - 1 || i==0) {
                cur += (numRows-1) * 2;
                continue;
            }
            if (flag == 1) {
                cur += (numRows-(i+1))*2;
                flag = 0;
            }
            else { //flag == 0
                cur += (numRows -(numRows-i))*2;
                flag = 1;
            }
        }
    }
//    cout<<endl;
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "A";
    
    cout<<convert(s, 1);
    return 0;
}
