//
//  main.cpp
//  leetcode91. Decode Ways
//
//  Created by 陈梓玮 on 2022/7/29.
//https://leetcode.cn/problems/decode-ways/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 暴力后序递归超时
    // bool is_valid(string t){
    //     if(t.length() == 1 && t[0] != '0') return true;
    //     else{
    //         if(t[0] == '0')
    //             return false;
    //         else{
    //             int a = atoi(t.c_str());
    //             if(a <= 26 &&  a >=10)
    //                 return true;
    //             else return false;
    //         }
    //     }
    // }
    // int travrse(string s, int pos){
    //     if(pos == s.length())   //到结尾了
    //         return 1;
    //     string t = "";
    //     t+= s[pos];
    //     int sum1 = 0;int sum2 = 0;
    //     if(is_valid(t))
    //         sum1 = travrse(s, pos+1);
    //     if(pos+1<s.length()){
    //         t+=s[pos+1];
    //         if(is_valid(t))
    //             sum2 = travrse(s, pos+2);
    //     }
    //     return sum1+sum2;
    // }

    // int numDecodings(string s) {
    //     return travrse(s, 0);
    // }

// 动态规划，参考题解，边界条件很容易处理错
    bool is_valid(string t){
        if(t.length() == 1 && t[0] != '0') return true;
        else{
            if(t[0] == '0')
                return false;
            else{
                int a = atoi(t.c_str());
                if(a <= 26 &&  a >=10)
                    return true;
                else return false;
            }
        }
    }
    int numDecodings(string s) {
//        int *dp = new int[s.length()+1];
        vector<int> dp(s.length()+1, 0);
        
        dp[0] = is_valid(string(1, s[0]))==1?1:0;
//        memset(dp, 0, sizeof(int)*s.length()+1);
        for(int i = 1; i <= s.length(); ++i) {
            string t = "";
            t+=s[i-1];
            if(is_valid(t))
                dp[i] +=dp[i-1];
            if(i>=2){
                t.insert(t.begin(), s[i-2]);
                if(is_valid(t))
                    dp[i] += dp[i-2];
            }
        }
        return dp[s.length()];
    }

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "226";
    cout<<numDecodings(s);
    
    std::cout << "Hello, World!\n";
    return 0;
}
