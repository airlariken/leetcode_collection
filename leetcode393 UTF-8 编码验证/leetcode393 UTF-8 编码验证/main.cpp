//
//  main.cpp
//  leetcode393 UTF-8 编码验证
//
//  Created by 陈梓玮 on 2022/3/13.
//

#include <iostream>
#include <vector>
using namespace std;


//  没做出来，题目没读清楚，题目给的是vector<int>每个元素就是一个8bit转成十进制的数
//  有空有缘再写吧


    const int Byte = 8;
    bool isUTF8(vector<int>& data, int code_pointer){
        int char_bytes = -1;
        for(int i = 0; i < 5; ++i){
            if(data[code_pointer+i] == 0){
                //意味着当前编码读到了0，若是一个utf8编码的字符，则拥有i个字节
                char_bytes = i - 1;
            }
        }
        if(char_bytes == -1 || char_bytes == 1)    return false;//若以10开头或者11111或更多1开头的情况直接寄了
        if(char_bytes == 0) char_bytes = 1;     //第一个为0的是1字节字符
        if(char_bytes == 2){
            if(!(data[code_pointer + Byte] == 1 && data[code_pointer + Byte + 1] == 0))
                return false;
        }
        for(int i = 1; i < char_bytes; ++i){
            if(!(data[code_pointer + Byte*i] == 1 && data[code_pointer + Byte*i + 1] == 0))
                return false;
        }
        code_pointer += Byte*char_bytes;
        return true;
    }
    bool validUtf8(vector<int>& data) {
        int code_pointer = 0;
        while(code_pointer < data.size())
            if(!isUTF8(data, code_pointer))
                return false;
        return true;
    }

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    return 0;
}
