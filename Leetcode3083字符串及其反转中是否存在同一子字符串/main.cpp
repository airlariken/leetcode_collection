//
// Created by 橙子味 on 2024/12/26.
//
#include <iostream>
using namespace std;
#include <algorithm>
bool isSubstringPresent(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    // 匹配
    for(auto it = s.begin(); it != s.end(); ++it){
        for(auto it2 = it+1; it2 != s.end(); ++it2){
          string sub_s = s.substr(it-s.begin(), it2-it+1);
          auto flag = rev_s.find(sub_s);
          // auto i = find(rev_s.begin(), rev_s.end(), sub_s);
          //   if(i != rev_s.end()) {
          //       return true;
          //   }
          if(flag != string::npos) {
              cout << sub_s << endl;
              return true;
          }
        }
    }
    return false;
}
int main() {
    string s = "Hello, World!";
    bool res = isSubstringPresent(s);
    cout<<res;
}
