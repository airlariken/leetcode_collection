//
//  main.cpp
//  leetcode139. 单词拆分
//
//  Created by 陈梓玮 on 2022/7/31.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool compare(string s, string word, int cur){
    if (s.length()<word.length()+cur)
        return false;
    for(int i = cur; i < cur+word.length(); ++i){
        if(s[i] != word[i-cur])
            return false;
    }
    return true;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        bool *dp = new bool[s.length()+1];
        memset(dp, 0, sizeof(bool)*(s.length()+1));
        dp[0] = true;       //dp数组表示前i个字符的串能由wordDict组成
        for(int i = 0 ; i < s.length(); ++i){
            if(dp[i] == false)
                continue;
            for(auto it = wordDict.begin(); it!=wordDict.end();++it)
                if(compare(s, *it, i)){
                    dp[i+it->length()] = true;
                    if(i+it->length()==s.length())      //提前终止
                        return true;
                }
                    
        }
        return dp[s.length()];
    }
int main(int argc, const char * argv[]) {
    string s = "leetcode";
    vector<string> wordDict;
    wordDict.push_back("leet");
    wordDict.push_back("code");
    cout<<wordBreak(s, wordDict)<<endl;
    return 0;
}
