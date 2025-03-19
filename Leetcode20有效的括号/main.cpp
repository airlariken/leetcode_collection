//
// Created by 橙子味 on 2025/3/19.
//
#include <string>
#include <stack>
using namespace std;

inline bool isMatch(char left, char right){
    return  (left == '[' && right == ']') ||  (left == '(' && right == ')')  || (left == '{' && right == '}') ;
}
bool isValid(string s) {
    stack<char> s_s;
    for(char c : s){
        if (c == '(' ||c == '[' ||c == '{') {
            s_s.push(c);
            continue;
        }
        if(s_s.empty()) return false;
        char stack_top = s_s.top();
        if (isMatch(stack_top,  c))   s_s.pop();
        else return false;
    }
    if(!s_s.empty()) return false;
    return true;
}