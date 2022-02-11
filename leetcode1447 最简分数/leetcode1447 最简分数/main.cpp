//
//  main.cpp
//  leetcode1447 最简分数
//
//  Created by 陈梓玮 on 2022/2/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool mgcd(int a, int b)
{
    if (a<b) {
        int t = a;
        b = t;
        a = b;
    }

    while(b != 0 && a%b) {
        int t = b;
        b = a%b;
        a = t;
    }
    if (b == 1)
        return true;
    else return false;
}
vector<string> simplifiedFractions(int n) {
    vector<string> res;
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j < i; ++j)
        {
            if (mgcd(i, j) == true) {
                string tmp_str = "";
                tmp_str += (char)(j+'0');tmp_str +="/";tmp_str +=(char)(i+'0');
                res.push_back(tmp_str);
            }
        }
    }
    for (auto i : res)
        cout<<i<<'\t';
    return res;
}

int main(int argc, const char * argv[]) {
    simplifiedFractions(4);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
