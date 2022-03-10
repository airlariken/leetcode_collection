//
//  main.cpp
//  leetcode537 复数乘法
//
//  Created by 陈梓玮 on 2022/2/25.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string complexNumberMultiply(string num1, string num2) {
    auto fi = num1.find("+");
    string front1 = num1.substr(0,fi);
//    cout<<front<<endl;
    string rare1 = num1.substr(fi+1, num1.length());
    fi = num2.find("+");
    string front2 = num2.substr(0,fi);
    string rare2 = num2.substr(fi+1, num1.length());
    int real = atoi(front1.c_str())*atoi(front2.c_str()) - atoi(rare1.c_str())*atoi(rare2.c_str());
    int complex = atoi(front1.c_str())*atoi(rare2.c_str())+atoi(front2.c_str())*atoi(rare1.c_str());
    string s = to_string(real);
    s +="+";
    s += to_string(complex);
    s+= "i";
    cout<<s;
    return s;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string n1 = "1+-1i";
    string n2 = "0+0i";
    complexNumberMultiply(n1, n2);
    std::cout << "Hello, World!\n";
    return 0;
}
