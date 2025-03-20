//
// Created by 橙子味 on 2025/3/20.
// 基于递归的回溯，第一版写的依托答辩，判断+重复代码很多
#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<string> res;
    string single_res = "";
    int left_brackets = 0;
public:
    void dfs(int n){
        if (single_res.length() == n*2) {res.emplace_back(single_res); return;}
        if (left_brackets == 0){
            ++left_brackets;
            single_res+="(";
            dfs(n);
            --left_brackets;
            single_res = single_res.substr(0, single_res.length()-1);
        }
        else if (n*2 - single_res.length() ==  left_brackets ){
            single_res += ")";
            --left_brackets;
            dfs(n);
            single_res = single_res.substr(0, single_res.length()-1);
            ++left_brackets;
        }
        else{
            single_res += "(";
            ++left_brackets;
            dfs(n);
            --left_brackets;
            single_res = single_res.substr(0, single_res.length()-1);

            single_res += ")";
            --left_brackets;
            dfs(n);
            single_res = single_res.substr(0, single_res.length()-1);
            ++left_brackets;
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n);
        return res;
    }
};
