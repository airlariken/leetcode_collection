//
//  main.cpp
//  leetcode917 仅仅反转字母
//
//  Created by 陈梓玮 on 2022/2/23.
//

#include <iostream>
#include <string>
using namespace std;
string reverseOnlyLetters(string s) {
    string res;
    int i = 0, j = (int)s.length()-1;
    if (s.length() == 0)
        return string();
    while(i < (int)s.length()){
        if(!((s[i] <= 'Z' && s[i] >= 'A') ||( s[i] <= 'z' && s[i] >= 'a'))) { //若不是字母
            res+=s[i];
            ++i;
        }
        else if((s[j] <= 'Z' && s[j] >= 'A') ||( s[j] <= 'z' && s[j] >= 'a')) {
            res += s[j];
            --j;
            ++i;
        }
        else {
            --j;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {

    string s = "7_28]";
    cout<<reverseOnlyLetters(s)<<endl;
    return 0;
}
