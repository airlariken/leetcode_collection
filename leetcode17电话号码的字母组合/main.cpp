//
// Created by 橙子味 on 2025/3/19.
// 字典+递归维护访问栈，参考过答案，需要重写
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> res;
    string single_res = "";
public:
    void dfs(int n, string &digits){
        if(single_res.length()==digits.length()) res.emplace_back(single_res);
        for(int i = 0; i<phoneMap[digits[single_res.length()]].length(); ++i){
            single_res += phoneMap[digits[single_res.length()]][i];
            dfs(i+1, digits);
            single_res = single_res.substr(0, single_res.length()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return vector<string>();
        dfs(0, digits);
        return res;
    }
};